#!/bin/bash

# 初始化参数
datasets=()
testsets=()

# 使用getopts处理命名参数
while (( "$#" )); do
  case "$1" in
    --datasets)
      shift
      while (( "$#" )) && [[ "$1" != --* ]]; do
        datasets+=("$1")
        shift
      done
      ;;
    --testsets)
      shift
      while (( "$#" )) && [[ "$1" != --* ]]; do
        testsets+=("$1")
        shift
      done
      ;;
    --) # 结束参数处理
      shift
      break
      ;;
    -*|--*=) # 不支持的参数
      echo "Error: Unsupported flag $1" >&2
      exit 1
      ;;
  esac
done

# 在这里，你可以使用$datasets和$testsets数组
echo "Datasets: ${datasets[@]}"
echo "Testsets: ${testsets[@]}"

# 你的其他代码...



#dataset=$1
#testset=$2
#shift 2
#subsets=($@)

seeds=(1000)
for seed in "${seeds[@]}"; do
  for dataset in "${datasets[@]}"; do
    for testset in "${testsets[@]}"; do
      dataset_root="../../devign_storage"
      output_root="$dataset_root/$dataset"
      if [ ! -d "$output_root" ]; then
        mkdir -p "$output_root"
      fi

  #    trains=$(find ../"$dataset"/data/"$subset"/ -type f -name "*train*")
      processed_test_path=../../devign_storage/shard/$testset
      tests=$(find ../../devign_storage/shard/$testset -type f -name "*shard*")
  #    echo "$tests"

      exec python -u ../code/main.py \
      --mode test \
      --dataset_root $dataset_root \
      --train_mode step_2000 \
      --dataset $dataset \
      --seed "$seed" \
      --model_type devign \
      --test_src $tests \
      --processed_test_path $processed_test_path \
      2>&1 | tee "$output_root/${testset}_$seed.log"

    done
  done
done