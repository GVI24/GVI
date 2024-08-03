cd ../linevul/scripts
datasets="train_reveal"
testsets="test_devign"
bash test.sh --datasets $datasets --testsets $testsets

datasets="train_reveal"
testsets="test_bigvul"
bash test.sh --datasets $datasets --testsets $testsets


datasets="train_reveal+gvi5000"
testsets="test_devign"
bash test.sh --datasets $datasets --testsets $testsets

datasets="train_reveal+gvi5000"
testsets="test_bigvul"
bash test.sh --datasets $datasets --testsets $testsets