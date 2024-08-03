rm -rf /home/raw_code
cp -R /root/reveal/static_check/cppcheck/raw_code /home/raw_code
./tscancode --xml --enable=all /home/raw_code 2>tscancode.xml
