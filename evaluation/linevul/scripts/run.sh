# 定义一个函数来处理SIGINT信号
handle_sigint() {
    echo "脚本已被Ctrl+C终止"
    exit 1  # 退出脚本
}

# 使用trap命令来捕获SIGINT信号，并调用handle_sigint函数
trap handle_sigint SIGINT

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
#原来的batch size 16
seed=1000

for dataset in "${datasets[@]}"; do
  for trainset in "${trainsets[@]}"; do
    for partset in "${partsets[@]}"; do
      for testset1 in "${testsets1[@]}"; do
        for testset2 in "${testsets2[@]}"; do
          output_root="../../linevul_storage/$dataset"
          if [ ! -d "$output_root" ]; then
            mkdir -p "$output_root"
          fi
          trains=$(find ../../linevul_storage/json/$trainset -type f -name "*jsonl*")
          parts=$(find ../../linevul_storage/json/$partset -type f -name "*jsonl*")
          tests1=$(find ../../linevul_storage/json/$testset1 -type f -name "*jsonl*")
          tests2=$(find ../../linevul_storage/json/$testset2 -type f -name "*jsonl*")
          if [ "$partset" == "none" ]; then
            exec python -u ../code/linevul/linevul_main.py \
              --output_dir=$output_root/saved_models \
              --model_type=roberta \
              --tokenizer_name=microsoft/codebert-base \
              --model_name_or_path=microsoft/codebert-base \
              --do_train \
              --train_data_file=$trains \
              --test1_data_file=$tests1 \
              --test2_data_file=$tests2 \
              --epochs 8 \
              --block_size 512 \
              --train_batch_size 16 \
              --eval_batch_size 16 \
              --learning_rate 2e-5 \
              --max_grad_norm 1.0 \
              --evaluate_during_training \
              --seed $seed 2>&1 | tee "$output_root/${trainset}_${partset}_${testset1}_${testset2}_$seed.log"
            else
              exec python -u ../code/linevul/linevul_main.py \
              --output_dir=$output_root/saved_models \
              --model_type=roberta \
              --tokenizer_name=microsoft/codebert-base \
              --model_name_or_path=microsoft/codebert-base \
              --do_train \
              --train_data_file=$trains \
              --part_data_file=$parts \
              --test1_data_file=$tests1 \
              --test2_data_file=$tests2 \
              --epochs 8 \
              --block_size 512 \
              --train_batch_size 16 \
              --eval_batch_size 16 \
              --learning_rate 2e-5 \
              --max_grad_norm 1.0 \
              --evaluate_during_training \
              --seed $seed 2>&1 | tee "$output_root/${trainset}_${partset}_${testset1}_${testset2}_$seed.log"
            fi
        done
      done
    done
  done
done


#set=$1
#shift
##datasets=("generalization_baseline" "generalization_my_gen" "same_set_baseline" "same_set_my_gen")
##datasets=("generalization_my_gen")
#datasets=("$@")
#for dataset in "${datasets[@]}"
#do
#  output_root="../$set/data_storage_$(echo $dataset | sed s@/@-@g)"
#  if [ ! -d "$output_root" ]; then
#    mkdir -p "$output_root"
#  fi
#
#  seed=123456
#
#  python ../code/linevul/linevul_main.py \
#    --output_dir=$output_root/saved_models \
#    --model_type=roberta \
#    --tokenizer_name=microsoft/codebert-base \
#    --model_name_or_path=microsoft/codebert-base \
#    --do_train \
#    --do_test \
#    --train_data_file=../$set/data/$dataset/train.jsonl \
#    --eval_data_file=../$set/data/$dataset/train.jsonl \
#    --test_data_file=../$set/data/$dataset/test.jsonl \
#    --epochs 10 \
#    --block_size 512 \
#    --train_batch_size 16 \
#    --eval_batch_size 16 \
#    --learning_rate 2e-5 \
#    --max_grad_norm 1.0 \
#    --evaluate_during_training \
#    --seed $seed 2>&1 | tee "$output_root/$(echo $dataset | sed s@/@-@g).log"
#
#done
