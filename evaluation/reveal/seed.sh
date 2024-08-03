# 定义一个函数来处理SIGINT信号
handle_sigint() {
    echo "脚本已被Ctrl+C终止"
    exit 1  # 退出脚本
}

# 使用trap命令来捕获SIGINT信号，并调用handle_sigint函数
trap handle_sigint SIGINT

declare -A dateset_srcs=(
    ["reveal_baseline"]="/root/reveal/data/reveal_baseline"
    ["reveal_gen"]="/root/reveal/data/reveal_gen"
)
dataset_root="/root/reveal/data_storage"

seeds=(3407 100 128 256 500 512 1024 2000 5000 10000 20000 50000)

for seed in "${seeds[@]}"; do
  for dataset in "${!dateset_srcs[@]}"; do
    mkdir -p "$dataset_root/$dataset/models-seed$seed"
    printf "processing $dataset seed $seed\n"
    python -u main.py --dataset "$dataset" \
    --train_src "${dateset_srcs[$dataset]}/reveal_train_after_ggnn.json" \
    --test_src "${dateset_srcs[$dataset]}/reveal_test_after_ggnn.json" \
    --seed $seed --balance True \
    > "$dataset_root/$dataset/models-seed$seed/$dataset.out" \
    2> "$dataset_root/$dataset/models-seed$seed/$dataset.err"
  done
done


seeds_2=(32 234 320 348 438 490 495 3243 4035 4238 4550 5480 5940 7598 7865 9343 34323 78596 454854 937520)

for seed in "${seeds_2[@]}"; do
  for dataset in "${!dateset_srcs[@]}"; do
    mkdir -p "$dataset_root/$dataset/models-seed$seed"
    printf "processing $dataset seed $seed\n"
    python -u main.py --dataset "$dataset" \
    --train_src "${dateset_srcs[$dataset]}/reveal_train_after_ggnn.json" \
    --test_src "${dateset_srcs[$dataset]}/reveal_test_after_ggnn.json" \
    --seed $seed --balance True \
    > "$dataset_root/$dataset/models-seed$seed/$dataset.out" \
    2> "$dataset_root/$dataset/models-seed$seed/$dataset.err"
  done
done