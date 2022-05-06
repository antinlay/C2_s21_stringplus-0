#!/bin/bash
echo '--------------RUN TEST--------------'
if (test -f test);
then
    for ((i=1; i<=100;i++))
        do
        ./test
        done
# else
#     cd ../../src/
#     make test
#     timeout 10 ping google.com
#     cd ../materials/build
#     for ((i=1; i<=100;i++))
#         do
#         test
#         done
fi
# make clean
echo '--------------END TEST--------------'