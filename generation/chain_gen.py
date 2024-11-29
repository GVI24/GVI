import json
import os
import warnings
import pdb

from langchain.chains import ConversationChain
from langchain.memory import ConversationBufferMemory
from langchain_core.prompts import ChatPromptTemplate, MessagesPlaceholder, HumanMessagePromptTemplate, \
    SystemMessagePromptTemplate
from langchain_openai import ChatOpenAI
from tqdm import tqdm
import random
from collections import Counter
import config

warnings.filterwarnings('ignore')
os.environ["OPENAI_API_KEY"] = config.OPENAI_API_KEY
MODEL = config.MODEL
origin_data = config.origin_data
origin_vul_data = config.origin_vul_data
cot_inputs = config.cot_inputs
chain_sys = config.chain_sys
chain_inputs = config.chain_inputs
gen_output_root = config.gen_output_root
gen_output_result_root = config.gen_output_result_root


def get_output_path(index, file_name):
    if not os.path.exists(gen_output_root):
        os.mkdir(gen_output_root)
    output_dir = os.path.join(gen_output_root, str(index))
    if not os.path.exists(output_dir):
        os.mkdir(output_dir)
    output_path = os.path.join(output_dir, file_name)
    return output_path


def gen():
    with open(origin_data, 'r') as f:
        data = json.load(f)
        # data = [x for x in data if 400 < len(x['code']) <= 800]
        print(len(data))

    chat = ChatOpenAI(
        # model_name='gpt-4-1106-preview',
        model_name=MODEL,
        streaming=True,
        # callbacks=[StreamingStdOutCallbackHandler()],
        temperature=.9
    )
    prompt = ChatPromptTemplate.from_messages([
        SystemMessagePromptTemplate.from_template(chain_sys),
        MessagesPlaceholder(variable_name="history"),
        HumanMessagePromptTemplate.from_template("{input}")
    ])
    memory = ConversationBufferMemory(memory_key="history", return_messages=True)
    conversation = ConversationChain(memory=memory, prompt=prompt, llm=chat, verbose=False)

    for index, item in enumerate(tqdm(data)):
        # index: data中的索引
        # idx: 生成文件的索引

        idx = index

        for chain_input in chain_inputs:
            # pdb.set_trace()
            # conversation.predict(input=chain_input.format(code=item['code']))
            conversation.predict(input=chain_input.format(code=index))

        output_path = get_output_path(idx, item['file_name'])
        with open(output_path, 'w') as f:
            f.write(f'System: {chain_sys}\n')
            f.write(memory.buffer_as_str)
        memory.clear()
        # assert 0
    # if not os.path.exists(gen_output_result_root):
    #     os.mkdir(gen_output_result_root)


def few_shot():
    dataset = 'bigvul'
    train_path = f'./{dataset}_revision_left_2.json'
    test_path = f'./{dataset}_revision_2.json'
    with open(train_path, 'r') as f:
        train_data = json.load(f)
    vul = [item for item in train_data if item['label'] == 1]
    saf = [item for item in train_data if item['label'] == 0]
    train_vul_data = [item for item in vul if 0 < len(item['code']) <= 300]
    train_saf_data = [item for item in saf if 0 < len(item['code']) <= 300]
    print(len(train_vul_data), len(train_saf_data))

    with open(test_path, 'r') as f:
        test_data = json.load(f)

    chat = ChatOpenAI(
        # model_name='gpt-4-1106-preview',
        model_name=MODEL,
        streaming=True,
        # callbacks=[StreamingStdOutCallbackHandler()],
        temperature=.9
    )

    prompt = ChatPromptTemplate.from_messages([
        SystemMessagePromptTemplate.from_template(chain_sys),
        MessagesPlaceholder(variable_name="history"),
        HumanMessagePromptTemplate.from_template("{input}")
    ])

    memory = ConversationBufferMemory(memory_key="history", return_messages=True)
    conversation = ConversationChain(memory=memory, prompt=prompt, llm=chat, verbose=False)

    for index, item in enumerate(tqdm(test_data)):
        # index: data中的索引
        # idx: 生成文件的索引
        idx = index
        vul_examples = random.sample(train_vul_data, 10)
        saf_examples = random.sample(train_saf_data, 10)

        for chain_input in chain_inputs:
            # pdb.set_trace()
            # cot-shot
            # c_input = chain_input.format(code=item['code'])
            # 5-shot
            # c_input = chain_input.format(
            #     example0=vul_examples[0]['code'], label0='yes',
            #     example1=saf_examples[0]['code'], label1='no',
            #     example2=saf_examples[1]['code'], label2='no',
            #     example3=saf_examples[2]['code'], label3='no',
            #     example4=saf_examples[3]['code'], label4='no',
            #     code=item['code'])
            # 10-shot
            # c_input = chain_input.format(
            #     example0=saf_examples[0]['code'], label0='no',
            #     example1=saf_examples[1]['code'], label1='no',
            #     example2=saf_examples[2]['code'], label2='no',
            #     example3=saf_examples[3]['code'], label3='no',
            #     example4=saf_examples[4]['code'], label4='no',
            #     example5=vul_examples[0]['code'], label5='yes',
            #     example6=vul_examples[1]['code'], label6='yes',
            #     example7=vul_examples[2]['code'], label7='yes',
            #     example8=vul_examples[3]['code'], label8='yes',
            #     example9=vul_examples[4]['code'], label9='yes',
            #     code=item['code'])

            c_input = chain_input.format(
                example0=vul_examples[0]['code'], label0='yes',
                example1=vul_examples[1]['code'], label1='yes',
                example2=vul_examples[2]['code'], label2='yes',
                example3=vul_examples[3]['code'], label3='yes',
                example4=vul_examples[4]['code'], label4='yes',
                example5=vul_examples[5]['code'], label5='yes',
                example6=vul_examples[6]['code'], label6='yes',
                example7=vul_examples[7]['code'], label7='yes',
                example8=vul_examples[8]['code'], label8='yes',
                example9=vul_examples[9]['code'], label9='yes',
                example10=saf_examples[0]['code'], label10='no',
                example11=saf_examples[1]['code'], label11='no',
                example12=saf_examples[2]['code'], label12='no',
                example13=saf_examples[3]['code'], label13='no',
                example14=saf_examples[4]['code'], label14='no',
                example15=saf_examples[5]['code'], label15='no',
                example16=saf_examples[6]['code'], label16='no',
                example17=saf_examples[7]['code'], label17='no',
                example18=saf_examples[8]['code'], label18='no',
                example19=saf_examples[9]['code'], label19='no',
                code=item['code'])
            # pdb.set_trace()
            conversation.predict(input=c_input)
        # pdb.set_trace()
        output_path = get_output_path(idx, item['file_name'])
        # print(memory.buffer_as_str)
        # assert 0
        with open(output_path, 'w') as f:
            f.write(f'System: {chain_sys}\n')
            f.write(memory.buffer_as_str)
        memory.clear()


if __name__ == "__main__":
    gen()
    # few_shot()
