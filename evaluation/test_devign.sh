cd /root/my_eval/RQ1/devign/scripts
datasets="train_devign"
testsets="test_reveal"
bash test.sh --datasets $datasets --testsets $testsets

datasets="train_devign"
testsets="test_bigvul"
bash test.sh --datasets $datasets --testsets $testsets