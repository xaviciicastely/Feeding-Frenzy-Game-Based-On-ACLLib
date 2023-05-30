# 使用C/C++语言设计基于ACLLib图形库的精灵游戏（大鱼吃小鱼）
## 游戏说明
使用C/C++语言设计了一个基于`ACLLib`图形库的大鱼吃小鱼精灵游戏，它具有大鱼吃小鱼这类游戏的基本功能：玩家可以控制自己的鱼在“海中”进行游弋，在不断捕食比自己等级低的鱼、增加自己的分以达到升级变大所需条件的同时，还要避免被比自己等级大的NPC鱼吃掉，否则游戏结束。运行游行需要在`VS Code`终端输入命令行，进行编译后执行游戏。
## 编译运行说明
游戏所在文件夹`Feeding Frenzy`含有`ACLLib`库头文件和C语言文件：`acllib.h`, `acllib.c`;同时含有实现大鱼吃小鱼游戏中基类鱼的头文件和cpp文件：`FishBase.h`, `FishBase.cpp`；玩家所控制鱼的头文件和cpp：`PlayerFish.h`, `PlayerFish.cpp`；NPC鱼的头文件和cpp文件：`Fishlv1shrimp.h`, `Fishlv1shrimp.cpp`, `Fishlv2littlefish.h`, `Fishlv2littlefish.cpp`, `Fishlv3whale.h`, `Fishlv3whale`；主文件`StartGame`。 本游戏使用命令行编译器MinGW把源代码编译成最终的可执行程序。具体步骤是先在在`Vs Code`打开文件夹`Feeding Frenzy`，新建cmd终端，输入以下三行编译命令（每输入一行按下回车键）：
```
gcc -c *.c  
g++ -c *.cpp
g++ *.o -lgdi32 -lole32 -loleaut32 -luuid -lwinmm – 
lmsimg32 -o game.exe
```
其中，“gcc -c \*.c”命令用以编译ACLLIB库文件和各类鱼头文件；“g++ -c \*.cpp”用来编译实现各类鱼功能的cpp文件；“g++ \*.o -lgdi32 -lole32 -loleaut32 -luuid -lwinmm -lmsimg32 -o game.exe”用来调用命令行编译器MinGW生成一个名为”game.exe”可执行文件。  
然后输入以下命令运行可执行文件，进入游戏初始界面：
```
game.exe
```
