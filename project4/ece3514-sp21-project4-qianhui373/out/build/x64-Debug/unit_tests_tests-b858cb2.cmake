add_test( [==[test sparse]==] C:/Users/project4/ece3514-sp21-project4-qianhui373/out/build/x64-Debug/unit_tests.exe [==[test sparse]==])
set_tests_properties( [==[test sparse]==] PROPERTIES WORKING_DIRECTORY C:/Users/project4/ece3514-sp21-project4-qianhui373/out/build/x64-Debug)
add_test( [==[dot test]==] C:/Users/project4/ece3514-sp21-project4-qianhui373/out/build/x64-Debug/unit_tests.exe [==[dot test]==])
set_tests_properties( [==[dot test]==] PROPERTIES WORKING_DIRECTORY C:/Users/project4/ece3514-sp21-project4-qianhui373/out/build/x64-Debug)
set( unit_tests_TESTS [==[test sparse]==] [==[dot test]==])