# my-calculator
c++编写的，结合了windows自带计算器与上学时的科学计算器功能，CUI交互界面，拥有良好的错误提示与处理。
支持普通计算器、日期计算器、程序员计算器、批处理、历史记录处理、批处理、自定义设置等等。

main.cpp 所有接口均在此调用，便于更新为GUI
ToPostfix.h 将表达式转换为后缀表达式被common.h bigNumber.h programmer.h依赖
History.h 被main.cpp依赖
set.h 目前不如学生用科学计算器设置功能复杂，需要完善，设置格式信息
common.h 统计计算功能尚未完善

history.log 记录历史信息，会自动生成
mySet.set 计算器设置，可手动设置，目前功能待完善
help.txt 可直接查看帮助或者在菜单界面输入help查看
