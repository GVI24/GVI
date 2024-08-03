# 定义一个函数来处理SIGINT信号
handle_sigint() {
    echo "脚本已被Ctrl+C终止"
    exit 1  # 退出脚本
}

# 使用trap命令来捕获SIGINT信号，并调用handle_sigint函数
trap handle_sigint SIGINT


# 初始化参数
datasets=()
seeds=()
epochs=()

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
    --seeds)
      shift
      while (( "$#" )) && [[ "$1" != --* ]]; do
        seeds+=("$1")
        shift
      done
      ;;
    --epochs)
      shift
      while (( "$#" )) && [[ "$1" != --* ]]; do
        epochs+=("$1")
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

# 在这里，你可以使用$datasets
echo "Datasets: ${datasets[@]}"
echo "Seeds: ${seeds[@]}"
echo "Epochs: ${epochs[@]}"


#seeds=($(seq 1 1000))
seeds=(1000)
#balance=(3)
for balance in 400; do
  for seed in "${seeds[@]}"; do
    for dataset in "${datasets[@]}"; do
      for epoch in "${epochs[@]}"; do
        dataset_root="/root/my_eval/RQ1/reveal_storage_3000"
        output_root="$dataset_root/$dataset"
        if [ ! -d "$output_root" ]; then
          mkdir -p "$output_root/models-seed${seed}_$balance"
        fi

  #      exec python -u main.py \
  #      --dataset_root $dataset_root \
  #      --dataset $dataset \
  #      --train_src "$dataset_root/ggnn/$dataset/models-seed1000/reveal_train_after_ggnn.json" \
  #      --test1_src "$dataset_root/ggnn/$dataset/models-seed1000/reveal_test1_after_ggnn.json" \
  #      --test2_src "$dataset_root/ggnn/$dataset/models-seed1000/reveal_test2_after_ggnn.json" \
  #      --seed $seed \
  #      --epochs $epoch \
  #      --balance False \
  #      2>&1 | tee "$output_root/${dataset}_$seed.log"
        exec python -u main.py \
        --dataset_root $dataset_root \
        --dataset $dataset \
        --train_src "$dataset_root/ggnn/$dataset/models-seed1000/reveal_train_after_ggnn.json" \
        --test1_src "$dataset_root/ggnn/$dataset/models-seed1000/reveal_test1_after_ggnn.json" \
        --test2_src "$dataset_root/ggnn/$dataset/models-seed1000/reveal_test2_after_ggnn.json" \
        --seed $seed \
        --epochs $epoch \
        --balance $balance \
        2>&1 | tee "$output_root/${dataset}_${seed}_$balance.log"

      done
    done
  done
done


#for seed in "${seeds[@]}"; do
#  for dataset in "${!dateset_srcs[@]}"; do
#    mkdir -p "$dataset_root/$dataset/models-seed$seed"
#    printf "processing $dataset seed $seed\n"
#    python -u main.py --dataset "$dataset" \
#    --train_src "${dateset_srcs[$dataset]}/reveal_train_after_ggnn.json" \
#    --test_src "${dateset_srcs[$dataset]}/reveal_test_after_ggnn.json" \
#    --seed $seed --balance True \
#    > "$dataset_root/$dataset/models-seed$seed/$dataset.out" \
#    2> "$dataset_root/$dataset/models-seed$seed/$dataset.err"
#  done
#done

#python -u main.py --dataset nev \
#--train_src /root/reveal/data/nev/embed_reveal_devign_ori_train_after_ggnn.json \
#--test_src /root/reveal/data/nev/embed_reveal_devign_ori_test_after_ggnn.json \
#--seed 1000 \
#> /root/reveal/data_storage/nev/models-seed1000/nev.out \
#2> /root/reveal/data_storage/nev/models-seed1000/nev.err
#
#mkdir -p /root/reveal/data_storage/nev_ggnn/models-seed1000
#python -u main.py --dataset nev_ggnn \
#--train_src /root/reveal/data/nev_ggnn/reveal_train_after_ggnn.json \
#--test_src /root/reveal/data/nev_ggnn/reveal_test_after_ggnn.json \
#--seed 1000 \
#> /root/reveal/data_storage/nev_ggnn/nev_ggnn.out \
#2> /root/reveal/data_storage/nev_ggnn/nev_ggnn.err
#
#mkdir -p /root/reveal/data_storage/nev_ggnn_ori/models-seed1000
#python -u main.py --dataset nev_ggnn_ori \
#--train_src /root/reveal/data/nev_ggnn_ori/reveal_train_after_ggnn.json \
#--test_src /root/reveal/data/nev_ggnn_ori/reveal_test_after_ggnn.json \
#--seed 1000 \
#> /root/reveal/data_storage/nev_ggnn_ori/models-seed1000/nev_ggnn.out \
#2> /root/reveal/data_storage/nev_ggnn_ori/models-seed1000/nev_ggnn.err
#
#
#mkdir -p /root/reveal/data_storage/nev_shard/models-seed1000
#python -u main.py --dataset nev_shard \
#--train_src /root/reveal/data/nev_shard/reveal_train_after_ggnn.json \
#--test_src /root/reveal/data/nev_shard/reveal_test_after_ggnn.json \
#--seed 1000 \
#> /root/reveal/data_storage/nev_shard/models-seed1000/nev_shard.out \
#2> /root/reveal/data_storage/nev_shard/models-seed1000/nev_shard.err
#
#mkdir -p /root/reveal/data_storage/reveal_baseline_unbalance/models-seed1000
#python -u main.py --dataset reveal_baseline_unbalance \
#--train_src /root/reveal/data/reveal_baseline/reveal_train_after_ggnn.json \
#--test_src /root/reveal/data/reveal_baseline/reveal_test_after_ggnn.json \
#--seed 1000 --balance False \
#> /root/reveal/data_storage/reveal_baseline_unbalance/models-seed1000/reveal_baseline_unbalance.out \
#2> /root/reveal/data_storage/reveal_baseline_unbalance/models-seed1000/reveal_baseline_unbalance.err
#
#
#mkdir -p /root/reveal/data_storage/reveal_gen_unbalance/models-seed1000
#python -u main.py --dataset reveal_gen_unbalance \
#--train_src /root/reveal/data/reveal_gen/reveal_train_after_ggnn.json \
#--test_src /root/reveal/data/reveal_gen/reveal_test_after_ggnn.json \
#--seed 1000 --balance False \
#> /root/reveal/data_storage/reveal_gen_unbalance/models-seed1000/reveal_gen_unbalance.out \
#2> /root/reveal/data_storage/reveal_gen_unbalance/models-seed1000/reveal_gen_unbalance.err
#
#
#mkdir -p /root/reveal/data_storage/reveal_gen_input/models-seed1000
#python -u main.py --dataset reveal_gen_input \
#--train_src /root/reveal/data/reveal_gen_input/reveal_train_after_ggnn.json \
#--test_src /root/reveal/data/reveal_gen_input/reveal_test_after_ggnn.json \
#--seed 1000 --balance True \
#> /root/reveal/data_storage/reveal_gen_input/models-seed1000/reveal_gen_input.out \
#2> /root/reveal/data_storage/reveal_gen_input/models-seed1000/reveal_gen_input.err


#mkdir -p /root/reveal/data_storage/reveal_z2/models-seed1000
#python -u main.py --dataset reveal_z2 \
#--train_src /root/reveal/data/reveal_z2/reveal_train_after_ggnn.json \
#--test_src /root/reveal/data/reveal_z2/reveal_test_after_ggnn.json \
#--seed 1000 --balance True \
#> /root/reveal/data_storage/reveal_z2/models-seed1000/reveal_z2.out \
#2> /root/reveal/data_storage/reveal_z2/models-seed1000/reveal_z2.err
#
#mkdir -p /root/reveal/data_storage/reveal_z2_gen/models-seed1000
#python -u main.py --dataset reveal_z2_gen \
#--train_src /root/reveal/data/reveal_z2_gen/reveal_train_after_ggnn.json \
#--test_src /root/reveal/data/reveal_z2_gen/reveal_test_after_ggnn.json \
#--seed 1000 --balance True \
#> /root/reveal/data_storage/reveal_z2_gen/models-seed1000/reveal_z2_gen.out \
#2> /root/reveal/data_storage/reveal_z2_gen/models-seed1000/reveal_z2_gen.err