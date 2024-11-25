# 파일 빌드
g++ -o ./build/main ./src/main.cpp
# test 1 검사
./build/main < ./testcase/input_test1.txt  > output_test1.txt
diff ./testcase/answer_test1.txt output_test1.txt
# test 2 검사
./build/main < ./testcase/input_test2.txt  > output_test2.txt
diff ./testcase/answer_test2.txt output_test2.txt
# test 3 검사
./build/main < ./testcase/input_test3.txt  > output_test3.txt
diff ./testcase/answer_test3.txt output_test3.txt