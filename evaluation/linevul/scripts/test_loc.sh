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

