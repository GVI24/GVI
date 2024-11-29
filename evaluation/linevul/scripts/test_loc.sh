# 定义一个函数来处理SIGINT信号
handle_sigint() {
    echo "脚本已被Ctrl+C终止"
    exit 1  # 退出脚本
}

# 使用trap命令来捕获SIGINT信号，并调用handle_sigint函数
trap handle_sigint SIGINT

# 初始化参数
datasets=()
testsets1=()

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
    --testsets1)
      shift
      while (( "$#" )) && [[ "$1" != --* ]]; do
        testsets1+=("$1")
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
echo "Testsets1: ${testsets1[@]}"
#原来的batch size 16
seed=1000

for dataset in "${datasets[@]}"; do
      for testset1 in "${testsets1[@]}"; do
          output_root="../../linevul_storage/$dataset"
          if [ ! -d "$output_root" ]; then
            mkdir -p "$output_root"
          fi
          tests1=$(find ../../linevul_storage/json/$testset1 -type f -name "*csv")
          exec python -u ../code/linevul/linevul_main.py \
            --output_dir=$output_root/saved_models \
            --model_name=$output_root/saved_models/checkpoint-step87500/model.bin \
            --model_type=roberta \
            --tokenizer_name=microsoft/codebert-base \
            --model_name_or_path=microsoft/codebert-base \
            --do_test \
            --do_local_explanation \
            --top_k_constant=10 \
            --reasoning_method=attention \
            --test1_data_file=$tests1 \
            --block_size 512 \
            --write_raw_pred \
            --eval_batch_size 16 \
            --seed $seed 2>&1 | tee "$output_root/test_${testset1}_$seed.log"

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

#set=$1
#testset=$2
#shift 2
#datasets=("$@")
#
##datasets=("generalization_baseline" "generalization_my_gen" "same_set_baseline" "same_set_my_gen")
##datasets=("same_set_my_gen_old")
#for dataset in "${datasets[@]}"
#do
#  output_root="../$set/data_storage_$(echo $dataset | sed s@/@-@g)"
#  if [ ! -d "$output_root" ]; then
#    mkdir -p "$output_root"
#  fi
#
#  seed=1
#
#  python ../code/linevul/linevul_main.py \
#    --output_dir=$output_root/saved_models \
#    --model_type=roberta \
#    --tokenizer_name=microsoft/codebert-base \
#    --model_name_or_path=microsoft/codebert-base \
#    --do_test \
#    --test_data_file=../$set/data/$testset/test.jsonl \
#    --epochs 10 \
#    --block_size 512 \
#    --train_batch_size 16 \
#    --eval_batch_size 16 \
#    --learning_rate 2e-5 \
#    --max_grad_norm 1.0 \
#    --evaluate_during_training \
#    --seed $seed 2>&1 | tee "$output_root/test_$(echo $dataset | sed s@/@-@g)_on_$testset.log"
#
#done
