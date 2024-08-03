# 定义一个函数来处理SIGINT信号
handle_sigint() {
    echo "脚本已被Ctrl+C终止"
    exit 1  # 退出脚本
}

# 使用trap命令来捕获SIGINT信号，并调用handle_sigint函数
trap handle_sigint SIGINT



#!/bin/bash

# 初始化参数
datasets=()
trainsets=()
partsets=()
testsets1=()
testsets2=()

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
    --trainsets)
      shift
      while (( "$#" )) && [[ "$1" != --* ]]; do
        trainsets+=("$1")
        shift
      done
      ;;
    --partsets)
      shift
      while (( "$#" )) && [[ "$1" != --* ]]; do
        partsets+=("$1")
        shift
      done
      ;;
    --testsets1)
      shift
      while (( "$#" )) && [[ "$1" != --* ]]; do
        testsets1+=("$1")
        shift
      done
      ;;
    --testsets2)
      shift
      while (( "$#" )) && [[ "$1" != --* ]]; do
        testsets2+=("$1")
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
echo "Trainsets: ${trainsets[@]}"
echo "Partsets: ${partsets[@]}"
echo "Testsets1: ${testsets1[@]}"
echo "Testsets2: ${testsets2[@]}"

seeds=(1000)
for seed in "${seeds[@]}"; do
  for dataset in "${datasets[@]}"; do
    for trainset in "${trainsets[@]}"; do
      for partset in "${partsets[@]}"; do
        for testset1 in "${testsets1[@]}"; do
          for testset2 in "${testsets2[@]}"; do
            dataset_root="/root/my_eval/RQ1/reveal_storage_3000/ggnn"
            output_root="$dataset_root/$dataset"
            if [ ! -d "$output_root" ]; then
              mkdir -p "$output_root"
            fi

    #        processed_data_path=$output_root
            processed_train_path=/root/my_eval/RQ1/devign_storage/shard/$trainset
            processed_part_path=/root/my_eval/RQ1/devign_storage/shard/$partset
            processed_test1_path=/root/my_eval/RQ1/devign_storage/shard/$testset1
            processed_test2_path=/root/my_eval/RQ1/devign_storage/shard/$testset2
            trains=$(find /root/my_eval/RQ1/devign_storage/shard/$trainset -type f -name "*shard*")
            parts=$(find /root/my_eval/RQ1/devign_storage/shard/$partset -type f -name "*shard*")
            tests1=$(find /root/my_eval/RQ1/devign_storage/shard/$testset1 -type f -name "*shard*")
            tests2=$(find /root/my_eval/RQ1/devign_storage/shard/$testset2 -type f -name "*shard*")
    #        echo "$trains"
    #        echo "$tests"
    #        --processed_data_path $processed_data_path \
            if [ "$partset" == "none" ]; then
              exec python -u main.py \
              --mode train \
              --dataset_root $dataset_root \
              --train_mode step_2000 \
              --dataset $dataset \
              --seed "$seed" \
              --model_type ggnn \
              --train_src $trains \
              --test1_src $tests1 \
              --test2_src $tests2 \
              --processed_train_path $processed_train_path \
              --processed_test1_path $processed_test1_path \
              --processed_test2_path $processed_test2_path \
              2>&1 | tee "$output_root/${trainset}_${partset}_${testset1}_${testset2}_$seed.log"
            else
              exec python -u main.py \
              --mode train \
              --dataset_root $dataset_root \
              --train_mode step_2000 \
              --dataset $dataset \
              --seed "$seed" \
              --model_type ggnn \
              --train_src $trains \
              --part_src $parts \
              --test1_src $tests1 \
              --test2_src $tests2 \
              --processed_train_path $processed_train_path \
              --processed_part_path $processed_part_path \
              --processed_test1_path $processed_test1_path \
              --processed_test2_path $processed_test2_path \
              2>&1 | tee "$output_root/${trainset}_${partset}_${testset1}_${testset2}_$seed.log"
            fi
          done
        done
      done
    done
  done
done


#seeds=(1000)
#for seed in "${seeds[@]}"; do
#  for dataset in "${datasets[@]}"; do
#    for trainset in "${trainsets[@]}"; do
#      dataset_root="/root/my_eval/RQ1/reveal_storage/ggnn"
#      output_root="$dataset_root/$dataset"
#      if [ ! -d "$output_root" ]; then
#        mkdir -p "$output_root"
#      fi
#
#  #    trains=$(find ../"$dataset"/data/"$subset"/ -type f -name "*train*")
#      processed_train_path=/root/my_eval/RQ1/devign_storage/shard/$trainset
#      trains=$(find /root/my_eval/RQ1/devign_storage/shard/$trainset -type f -name "*shard*")
#  #    echo "$trains"
#
#      exec python -u main.py \
#      --mode train \
#      --dataset_root $dataset_root \
#      --train_mode step_2000 \
#      --dataset $dataset \
#      --seed "$seed" \
#      --model_type ggnn \
#      --train_src $trains \
#      --processed_train_path $processed_train_path \
#      2>&1 | tee "$output_root/${trainset}_$seed.log"
#
#    done
#  done
#done
#printf "processing reveal\n"
#python -u main.py --mode train --train_mode step_2000 --dataset reveal --train_src \
#/root/reveal/devign/data/output/gen_train/gen_train.json.shard1 \
#--seed 0 --model_type ggnn
#
#
#mkdir -p /root/reveal/devign/data_storage/nev_shard/models-seed1000
#python -u main.py --mode train --train_mode step_2000 --dataset nev_shard --train_src \
#/root/reveal/data/nev_shard/reveal_train.json.shard1 /root/reveal/data/nev_shard/reveal_train.json.shard2 \
#/root/reveal/data/nev_shard/reveal_train.json.shard3 /root/reveal/data/nev_shard/reveal_train.json.shard4 \
#--train_src \
#/root/reveal/data/nev_shard/devign_train.json.shard1 \
#--seed 1000 --model_type ggnn \
#> /root/reveal/devign/data_storage/nev_shard/models-seed1000/nev.out \
#2> /root/reveal/devign/data_storage/nev_shard/models-seed1000/nev.err
#
#
#mkdir -p /root/reveal/devign/data_storage/reveal_baseline/models-seed1000
#python -u main.py --mode train --train_mode step_2000 --dataset reveal_baseline --train_src \
#/root/reveal/data/reveal_gen/combined_reveal.json.shard1 /root/reveal/data/reveal_gen/combined_reveal.json.shard2 \
#/root/reveal/data/reveal_gen/combined_reveal.json.shard3 /root/reveal/data/reveal_gen/combined_reveal.json.shard4 \
#--train_src \
#/root/reveal/data/reveal_gen/devign_train.json.shard1 \
#--seed 1000 --model_type ggnn \
#> /root/reveal/devign/data_storage/reveal_baseline/models-seed1000/reveal_gen.out \
#2> /root/reveal/devign/data_storage/reveal_baseline/models-seed1000/reveal_gen.err
#
#mkdir -p /root/reveal/devign/data_storage/reveal_gen/models-seed1000
#python -u main.py --mode train --train_mode step_2000 --dataset reveal_gen --train_src \
#/root/reveal/data/reveal_gen/combined_reveal.json.shard1 /root/reveal/data/reveal_gen/combined_reveal.json.shard2 \
#/root/reveal/data/reveal_gen/combined_reveal.json.shard3 /root/reveal/data/reveal_gen/combined_reveal.json.shard4 \
#/root/reveal/data/reveal_gen/generated_reveal.json.shard1 /root/reveal/data/reveal_gen/generated_reveal.json.shard2 \
#--train_src \
#/root/reveal/data/reveal_gen/devign_train.json.shard1 \
#--seed 1000 --model_type ggnn \
#> /root/reveal/devign/data_storage/reveal_gen/models-seed1000/reveal_gen.out \
#2> /root/reveal/devign/data_storage/reveal_gen/models-seed1000/reveal_gen.err


#

#mkdir -p /root/reveal/devign/data_storage/reveal_2/models-seed1000
#python -u main.py --mode train --train_mode step_2000 --dataset reveal_2 --train_src \
#/root/reveal/devign/data/origin_output/reveal_2.json.shard1 /root/reveal/devign/data/origin_output/reveal_2.json.shard2 \
#/root/reveal/devign/data/origin_output/reveal_2.json.shard3 /root/reveal/devign/data/origin_output/reveal_2.json.shard4 \
#--train_src \
#/root/reveal/devign/data/origin_output/devign_train.json.shard1 \
#--seed 1000 --model_type ggnn \
#> /root/reveal/devign/data_storage/reveal_2/models-seed1000/reveal_2.out \
#2> /root/reveal/devign/data_storage/reveal_2/models-seed1000/reveal_2.err
#
#mkdir -p /root/reveal/devign/data_storage/reveal_2_gen/models-seed1000
#python -u main.py --mode train --train_mode step_2000 --dataset reveal_2_gen --train_src \
#/root/reveal/devign/data/origin_output/reveal_2.json.shard1 /root/reveal/devign/data/origin_output/reveal_2.json.shard2 \
#/root/reveal/devign/data/origin_output/reveal_2.json.shard3 /root/reveal/devign/data/origin_output/reveal_2.json.shard4 \
#/root/reveal/devign/data/origin_output/reveal_2_gen.json.shard1 \
#--train_src \
#/root/reveal/devign/data/origin_output/devign_train.json.shard1 \
#--seed 1000 --model_type ggnn \
#> /root/reveal/devign/data_storage/reveal_2_gen/models-seed1000/reveal_2_gen.out \
#2> /root/reveal/devign/data_storage/reveal_2_gen/models-seed1000/reveal_2_gen.err


#mkdir -p /root/reveal/devign/data_storage/reveal_2/models-seed1000_devign
#python -u main.py --mode train --train_mode step_2000 --dataset reveal_2 --train_src \
#/root/reveal/devign/data/origin_output/reveal_2.json.shard1 /root/reveal/devign/data/origin_output/reveal_2.json.shard2 \
#/root/reveal/devign/data/origin_output/reveal_2.json.shard3 /root/reveal/devign/data/origin_output/reveal_2.json.shard4 \
#--train_src \
#/root/reveal/devign/data/origin_output/devign_train.json.shard1 \
#--seed 1000 --model_type devign \
#> /root/reveal/devign/data_storage/reveal_2/models-seed1000_devign/reveal_2.out \
#2> /root/reveal/devign/data_storage/reveal_2/models-seed1000_devign/reveal_2.err
#
#mkdir -p /root/reveal/devign/data_storage/reveal_2_gen/models-seed1000_devign
#python -u main.py --mode train --train_mode step_2000 --dataset reveal_2_gen --train_src \
#/root/reveal/devign/data/origin_output/reveal_2.json.shard1 /root/reveal/devign/data/origin_output/reveal_2.json.shard2 \
#/root/reveal/devign/data/origin_output/reveal_2.json.shard3 /root/reveal/devign/data/origin_output/reveal_2.json.shard4 \
#/root/reveal/devign/data/origin_output/reveal_2_gen.json.shard1 \
#--train_src \
#/root/reveal/devign/data/origin_output/devign_train.json.shard1 \
#--seed 1000 --model_type devign \
#> /root/reveal/devign/data_storage/reveal_2_gen/models-seed1000_devign/reveal_2_gen.out \
#2> /root/reveal/devign/data_storage/reveal_2_gen/models-seed1000_devign/reveal_2_gen.err


