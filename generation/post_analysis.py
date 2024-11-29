import json
import os
from typing import Dict, List, Tuple

from langchain_community.document_loaders import JSONLoader
from langchain_community.embeddings import HuggingFaceEmbeddings
from langchain_community.vectorstores.chroma import Chroma
from matplotlib import pyplot as plt

import config

origin_data = config.origin_data
rm_comments_output = config.rm_comments_output
combine_json_1 = config.combine_json_1
combine_json_2 = config.combine_json_2
combine_json_output = config.combine_json_output
similarity_database_root = config.similarity_database_root
similarity_output = config.similarity_output
similarity_output_graph = config.similarity_output_graph
gen_output_result_root = config.gen_output_result_root

def metadata_func(json_obj: Dict, default_metadata: Dict) -> Dict:
    keys = ['id', 'file_name', 'file_path', 'code', 'label']
    for key in keys:
        value = json_obj.get(key, None)
        default_metadata[key] = value
    return default_metadata


def check_output():
    source_loader = JSONLoader(
        file_path=origin_data,
        jq_schema='.[]',
        content_key='code',
        metadata_func=metadata_func,
    )
    target_loader = JSONLoader(
        file_path=rm_comments_output,
        jq_schema='.[]',
        content_key='code',
        metadata_func=metadata_func,
    )
    source_documents = source_loader.load()
    target_documents = target_loader.load()

    persist_directory = similarity_database_root

    # model_id = 'Salesforce/codet5p-110m-embedding'
    embeddings = HuggingFaceEmbeddings()
    db = Chroma.from_documents(
        source_documents,
        embeddings,
        persist_directory=persist_directory,
        collection_metadata={"hnsw:space": "cosine"},

    )
    db.persist()
    db = None
    db = Chroma(
        persist_directory=persist_directory,
        embedding_function=embeddings,
        collection_metadata={"hnsw:space": "cosine"},
    )

    similarity = []
    for target in target_documents:
        result = db.similarity_search_with_score(
            target.page_content,
            k=1,
        )
        for src_doc, score in result:
            res = {
                'id': target.metadata['id'],
                'query_file_name': target.metadata['file_name'],
                'query_file_path': target.metadata['file_path'],
                'query_code': target.metadata['code'],
                'query_label': target.metadata['label'],
                'result_file_name': src_doc.metadata['file_name'],
                'result_file_path': src_doc.metadata['file_path'],
                'result_code': src_doc.metadata['code'],
                'result_label': src_doc.metadata['label'],
                'similarity_score': score
            }
            similarity.append(res)

    with open(similarity_output, 'w') as f:
        json.dump(similarity, f, indent=4)

def graph_hist():
    with open(similarity_output, 'r') as f:
        data = json.load(f)

    similarities = [x['similarity_score'] for x in data]

    plt.hist(similarities, bins=50, alpha=0.5)

    plt.xlabel('Similarity')
    plt.ylabel('Frequency')

    plt.savefig(similarity_output_graph)



def graph_box():
    with open(similarity_output, 'r') as f:
        data = json.load(f)
    similarities = [x['similarity_score'] for x in data]

    plt.boxplot(similarities)
    plt.ylabel('Similarity')
    plt.savefig(similarity_output_graph.replace('hist', 'box'))

def get_similar():
    out = []
    index = 0
    with open(similarity_output, 'r') as f:
        data = json.load(f)
    for item in data:
        if item['similarity_score'] <= 0.4:
            # item['id'] = index
            # index += 1
            frame = {
                'id': index,
                'file_name': item['query_file_name'],
                'file_path': item['query_file_path'],
                'code': item['query_code'],
                'label': item['query_label'],
                'similarity_score': item['similarity_score']
            }
            out.append(frame)
    path = os.path.join(gen_output_result_root, 'get_similar.json')
    with open(path, 'w') as f:
        json.dump(out, f, indent=4)
        print(len(out))

if __name__ == "__main__":
    # check_output()
    # graph_hist()
    graph_box()
    # get_similar()
