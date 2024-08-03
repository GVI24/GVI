set=$1
testset=$2
shift 2
datasets=("$@")

#datasets=("generalization_baseline" "generalization_my_gen" "same_set_baseline" "same_set_my_gen")
#datasets=("same_set_my_gen_old")
for dataset in "${datasets[@]}"
do
  output_root="../$set/data_storage_$(echo $dataset | sed s@/@-@g)"
  if [ ! -d "$output_root" ]; then
    mkdir -p "$output_root"
  fi

  seed=1

  python ../code/linevul/linevul_main.py \
    --output_dir=$output_root/saved_models \
    --model_type=roberta \
    --tokenizer_name=microsoft/codebert-base \
    --model_name_or_path=microsoft/codebert-base \
    --do_test \
    --test_data_file=../$set/data/$testset/test.jsonl \
    --epochs 10 \
    --block_size 512 \
    --train_batch_size 16 \
    --eval_batch_size 16 \
    --learning_rate 2e-5 \
    --max_grad_norm 1.0 \
    --evaluate_during_training \
    --seed $seed 2>&1 | tee "$output_root/test_$(echo $dataset | sed s@/@-@g)_on_$testset.log"

done
