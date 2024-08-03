#datasets="ggnn"
#trainsets="train_devign train_reveal test_bigvul train_devign+vulgen2436_4 train_devign+vgx2436 train_devign+vgx12874 train_devign+mygen train_reveal+vulgen6305_3 train_reveal+vgx6305 train_reveal+vgx12874 train_reveal+mygen"

#trainsets="train_devign"
#testsets1="test_reveal"
#testsets2="test_bigvul"
#
#cd /root/reveal/devign
#datasets="train_devign"
#partsets="none"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2
#
#datasets="train_devign+vulgen1268"
#partsets="vulgen1268"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2
#
#datasets="train_devign+vgx1268"
#partsets="vgx1268"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2

#datasets="train_devign+mygen1268_3"
#partsets="mygen1268_3"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2


trainsets="train_reveal"
testsets1="test_devign"
testsets2="test_bigvul"

cd /root/reveal/devign
#datasets="train_reveal"
#partsets="none"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2

#datasets="train_reveal+0001"
#partsets="0001"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2

#datasets="train_reveal+1001"
#partsets="1001"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2
#
#datasets="train_reveal+0101"
#partsets="0101"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2

#datasets="train_reveal+0011"
#partsets="0011"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2

datasets="train_reveal+0000"
partsets="0000"
bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2

cd /root/my_eval/RQ1
bash represent.sh
#
#datasets="train_reveal+vulgen5000_3"
#partsets="vulgen5000_3"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2
#
#datasets="train_reveal+vgx5000"
#partsets="vgx5000"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2
#
#datasets="train_reveal+mygen_reveal5000_3"
#partsets="mygen_reveal5000_3"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2
#
#cd /root/my_eval/RQ1
#bash represent.sh





trainsets="train_bigvul"
testsets1="test_devign"
testsets2="test_reveal"

cd /root/reveal/devign
#datasets="train_bigvul"
#partsets="none"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2
#
#datasets="train_bigvul+vgx10000"
#partsets="vgx10000"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2
#
#datasets="train_bigvul+mygen_bigvul10000"
#partsets="mygen_bigvul10000"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2
#
#datasets="train_bigvul+vulgen10000_3"
#partsets="vulgen10000_3"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2
#
#
#datasets="train_bigvul+vulgen10000_2"
#partsets="vulgen10000_2"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2

#datasets="train_bigvul+vulgen10000_7"
#partsets="vulgen10000_7"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets1 $testsets1 --testsets2 $testsets2

#cd /root/my_eval/RQ1
#bash represent.sh






#datasets="train_reveal+vulgen6305_6_test_devign"
#trainsets="train_reveal"
#partsets="vulgen6305_6"
#testsets="test_devign"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets $testsets
#
#datasets="train_reveal+vulgen6305_6_test_bigvul"
#trainsets="train_reveal"
#partsets="vulgen6305_6"
#testsets="test_bigvul"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets $testsets

#datasets="train_bigvul+mygen12329_test_devign"
#trainsets="train_bigvul"
#partsets="mygen12329"
#testsets="test_devign"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets $testsets
#
#datasets="train_bigvul+mygen12329_test_reveal"
#trainsets="train_bigvul"
#partsets="mygen12329"
#testsets="test_reveal"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets $testsets


#seeds=1000
#epochs=6
#cd /root/reveal
#datasets="train_reveal+vulgen6305_6_test_devign"
#bash run.sh --datasets $datasets --seeds $seeds --epochs $epochs
#
#datasets="train_reveal+vulgen6305_6_test_bigvul"
#bash run.sh --datasets $datasets --seeds $seeds --epochs $epochs

#datasets="train_bigvul+mygen12329_test_devign"
#bash run.sh --datasets $datasets --seeds $seeds --epochs $epochs
#
#datasets="train_bigvul+mygen12329_test_reveal"
#bash run.sh --datasets $datasets --seeds $seeds --epochs $epochs


#datasets="train_bigvul_test_devign"
#trainsets="train_bigvul"
#partsets="none"
#testsets="test_devign"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets $testsets
#
#datasets="train_bigvul_test_reveal"
#trainsets="train_bigvul"
#partsets="none"
#testsets="test_reveal"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets $testsets
#
#datasets="train_bigvul+vulgen6024_test_devign"
#trainsets="train_bigvul"
#partsets="vulgen6024"
#testsets="test_devign"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets $testsets
#
#datasets="train_bigvul+vulgen6024_test_reveal"
#trainsets="train_bigvul"
#partsets="vulgen6024"
#testsets="test_reveal"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets $testsets
#
#datasets="train_bigvul+vgx6024_test_devign"
#trainsets="train_bigvul"
#partsets="vgx6024"
#testsets="test_devign"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets $testsets
#
#datasets="train_bigvul+vgx6024_test_reveal"
#trainsets="train_bigvul"
#partsets="vgx6024"
#testsets="test_reveal"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets $testsets
#
#datasets="train_bigvul+vgx12874_test_devign"
#trainsets="train_bigvul"
#partsets="vgx12874"
#testsets="test_devign"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets $testsets
#
#datasets="train_bigvul+vgx12874_test_reveal"
#trainsets="train_bigvul"
#partsets="vgx12874"
#testsets="test_reveal"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets $testsets
#
#datasets="train_bigvul+mygen6024_test_devign"
#trainsets="train_bigvul"
#partsets="mygen6024"
#testsets="test_devign"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets $testsets
#
#datasets="train_bigvul+mygen6024_test_reveal"
#trainsets="train_bigvul"
#partsets="mygen6024"
#testsets="test_reveal"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --partsets $partsets --testsets $testsets











#datasets="train_reveal+vulgen6305_5_test_bigvul"
#trainsets="train_reveal+vulgen6305_5"
#testsets="test_bigvul"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
#
#datasets="train_reveal+vulgen6305_5_test_devign"
#trainsets="train_reveal+vulgen6305_5"
#testsets="test_devign"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets





#cd /root/reveal/devign

#datasets="train_devign_test_reveal"
#trainsets="train_devign"
#testsets="test_reveal"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
##
#datasets="train_devign+vulgen2436_4_test_reveal"
#trainsets="train_devign+vulgen2436_4"
#testsets="test_reveal"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
##
#datasets="train_devign+vgx2436_test_reveal"
#trainsets="train_devign+vgx2436"
#testsets="test_reveal"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
#
#datasets="train_devign+vgx12874_test_reveal"
#trainsets="train_devign+vgx12874"
#testsets="test_reveal"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
#
#datasets="train_devign+mygen_test_reveal"
#trainsets="train_devign+mygen"
#testsets="test_reveal"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
#
## test_devign
## train_reveal
#datasets="train_reveal_test_devign"
#trainsets="train_reveal"
#testsets="test_devign"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
#
#datasets="train_reveal+vulgen6305_3_test_devign"
#trainsets="train_reveal+vulgen6305_3"
#testsets="test_devign"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
#
#datasets="train_reveal+vgx6305_test_devign"
#trainsets="train_reveal+vgx6305"
#testsets="test_devign"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
##
#datasets="train_reveal+vgx12874_test_devign"
#trainsets="train_reveal+vgx12874"
#testsets="test_devign"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
##
#datasets="train_reveal+mygen_test_devign"
#trainsets="train_reveal+mygen"
#testsets="test_devign"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
#
## test_bigvul
## train_devign
#datasets="train_devign_test_bigvul"
#trainsets="train_devign"
#testsets="test_bigvul"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
#
#datasets="train_devign+vulgen2436_4_test_bigvul"
#trainsets="train_devign+vulgen2436_4"
#testsets="test_bigvul"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
#
#datasets="train_devign+vgx2436_test_bigvul"
#trainsets="train_devign+vgx2436"
#testsets="test_bigvul"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
#
#datasets="train_devign+vgx12874_test_bigvul"
#trainsets="train_devign+vgx12874"
#testsets="test_bigvul"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
##
#datasets="train_devign+mygen_test_bigvul"
#trainsets="train_devign+mygen"
#testsets="test_bigvul"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
#
## test_bigvul
## train_reveal
#datasets="train_reveal_test_bigvul"
#trainsets="train_reveal"
#testsets="test_bigvul"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
#
#datasets="train_reveal+vulgen6305_3_test_bigvul"
#trainsets="train_reveal+vulgen6305_3"
#testsets="test_bigvul"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
#
#datasets="train_reveal+vgx6305_test_bigvul"
#trainsets="train_reveal+vgx6305"
#testsets="test_bigvul"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
#
#datasets="train_reveal+vgx12874_test_bigvul"
#trainsets="train_reveal+vgx12874"
#testsets="test_bigvul"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets
##
#datasets="train_reveal+mygen_test_bigvul"
#trainsets="train_reveal+mygen"
#testsets="test_bigvul"
#bash run_reveal.sh --datasets $datasets --trainsets $trainsets --testsets $testsets

















