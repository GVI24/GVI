import argparse
from gensim.models import Word2Vec
import json
import os


def train(args):
    files = args.data_paths
    sentences = []
    for f in files:
        data = json.load(open(f))
        for e in data:
            code = e['code']
            sentences.append([token.strip() for token in code.split()])
    print(len(sentences))
    # print(sentences)
    # assert 0
    wvmodel = Word2Vec(sentences, min_count=args.min_occ, workers=8, vector_size=args.embedding_size)
    print('Embedding Size : ', wvmodel.vector_size)
    for i in range(args.epochs):
        wvmodel.train(sentences, total_examples=len(sentences), epochs=1)
    if not os.path.exists(args.save_model_dir):
        os.mkdir(args.save_model_dir)
    save_file_path = os.path.join(args.save_model_dir, args.model_name)
    wvmodel.save(save_file_path)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--data_paths', type=str, nargs='+',
                        default=['./data/gen_test/gen_test_cfg_full_text_files.json'])
    parser.add_argument('--min_occ', type=int, default=1)
    parser.add_argument('-bin', '--save_model_dir', type=str, default='./data/gen_test')
    parser.add_argument('-n', '--model_name', type=str, default='raw_code_gen_test.100')
    parser.add_argument('-ep', '--epochs', type=int, default=100)  # ?
    parser.add_argument('-eb', '--embedding_size', type=int, default=100)  # 100
    args = parser.parse_args()
    train(args)


if __name__ == '__main__':
    main()
