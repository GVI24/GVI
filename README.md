# GVI #

This is the implementation repository of paper: GVI: Guided Vulnerability Imagination for Boosting
Deep Vulnerability Detectors

## Description ##

We propose GVI, a novel approach aimed at generating vulnerable samples to boost deep vulnerability detectors. 

GVI takes inspiration from human learning with imagination and proposes exploring LLMs to imagine and create new, informative vulnerable samples from given seed vulnerabilities.

## Reproducibility ##
### Requirements ###
- Python==3.7.13
- torch==1.12.1
- transformers==4.25.1
- tqdm==4.62.3
- numpy==1.21.5
- scikit-learn==1.0.2

### Structure ###
    |-generation/ "implementation for generating vulnerable samples using GVI".
    |-examination/ "contains the code for evaluating the generated vulnerable samples."
    |   |-devign/ 
    |   |-reveal/
    |   |-linevul/
    |-results/ "tables of experimental results."

### Usage ###
Generate new vulnerable samples with GVI:
1. download the real-world vulnerability datasets and change the path in `generation/config.py` to the path of the datasets.
2. change the prompt mode in `GVI`, `CoT`, `5-shot`, `10-shot` in `generation/config.py`.
2. run `python generation/chain_gen.py` to generate vulnerable samples.
3. run `python generation/post_preprocess.py` to collect samples.

Reproduce the evaluation results:
1. download the storage data and model files by following link: https://drive.google.com/drive/folders/1ixTJRpR23ocNbmugL1-vbV4VQEbeh-yN?usp=sharing 
2. run `bash evaluation/test_devign.sh`,`bash evaluation/test_reveal.sh` and `bash evaluation/test_linevul.sh` to reproduce the evaluation results.

Evaluate your own data:
1. we provide the preprocess and train scripts in each detector's folder, you can use the scripts to preprocess the data and train the detector.


### Dataset ###
- Devign (a real-world vulnerable dataset collected from FFmpeg and QEMU) [1]
- ReVeal (a real-world vulnerable dataset collected from Debian and Chromium) [2]
- Big-Vul (a large scale real-world vulnerable dataset collected from CVE database) [3]

[1] Devign https://sites.google.com/view/devign

[2] ReVeal https://drive.google.com/drive/folders/1KuIYgFcvWUXheDhT--cBALsfy1I4utOy

[3] Big-Vul https://drive.google.com/file/d/1-0VhnHBp9IGh90s2wCNjeCMuy70HPl8X/view