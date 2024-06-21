[toc]



# 初级版本

## api

![event](photos/event.png)



### <mark>MapNode<mark>

为结点，提供图的结构

#### T data

数据

#### vector< MapNode*> from_ptr

记录信号从哪来

#### vector<MapNode*> to_ptr

记录信号要去哪



#### <mark>Map<mark>



### <mark>Element<mark>

为某个接口

#### int value

为其值

#### Gate *gate

指向自己所在的Gate门

#### Element(int value=0)

构造函数

#### setValue()

设置自己的值

#### void setGate(Gate *)

绑定门

#### getValue()

获取自己的值



### <marK>Gate<mark>
门与各种元件的统称

#### vector< MapNode *> in

各个输入接口

#### vector< MapNode *> out

各个输出接口

#### enum

列举各接口名称

####  vector< vector< int>>  delay;

二维数组，描述了in到out的延迟

 #### virtual vector< int >  figureValue()=0;

  计算各个out的值，返回一个temp表,记录信息，但不赋值

 ####  vector< bool > always(Time * pre);

  判断对应out的value与latestValue（调用latestValueGate（...））相比，是否发生了改变，返回一个bool数组，发生了变化，则为true,未发生变化，则为false

#### vector< int > lastValue(Time * time);

返回离判定点最近的一次value数组



### <mark>Event<mark>

记录各个输入值的更改,更改亦有先后,通过List进行管理，组成EventList

#### Element * element_ptr

记录更改的Element

#### int values


记录对应更改的值




### <mark>Time<mark>

为时间表，记录有驱动事件的时间，通过List进行管理

#### long long time

记录此时的时间

#### list< Event>* eventList_ptr

记录该时间的事件链

#### addEvent(Event *event);

增加event，先判定eventList_ptr是否已经生成（堆区），记得写析构函数。

### <mark>ListNode<mark>

链表结点模版

#### T data

#### ListNode *next

#### ListNode *last

### <mark>List<mark>

为双向链表模版

#### ListNode *head

头结点

#### ListNode *tail

尾结点

#### push_back(T data)

#### push_front(T data)

#### insert_front()

#### insert_back()

#### print()

### <mark>全局函数<mark>

#### void update(EventNode& );

更新Element对应的值，Gate进行定值，与先前定值进行比较，判断是否需要修改(调用Gate::always())，如要修改，将修改的out，进行传递(调用transmit(...))，并在对应时间添加事件。

####void addEvent(long long time,MapNode & ,value );

添加Elment改变的value到time时的events上

#### int latestValueElement(MapNode &,long long start,long long end);

搜索latestValue在start到end最末端的值[start,end)

#### vector< int > latestValueGate(Gate &,long long start,long long end);

搜索Gate所有out的latestValue在start到end最末端的值[start,end)，返回一个数组。

#### void transmit(MapNode &，int delay);

将该Element的值通过Map进行传递（但并不改变末端的值），只是添加事件。



### 全局变量

#### Time * now;

记录现在的时间

#### Time * pre

记录现在正在预言的时间

## 日志

### 2024.6.18

Gate类实现混乱，应当用MapNode作为其接口而不是Element，always()的if判断出了问题，可能是MapNode未写完。

figureValue与delay均未完成。

部分类忘记写构造函数。

### 2024.6.21

完成了Event类和Time类的实现，但Gate类的always(Time *time)的实现有些麻烦。需要用到`virtual vector< int >  figureValue()=0;`以及`vector< int > lastValue(Time * time);`这两个函数的实现有些麻烦。增加了全局变量 now与 pre，记录两个时间。增加了Time的成员函数`void addEvent(Event *event);`但现在还没来的及写实现，忘记写Time的析构函数了，因为eventList是放在堆区的。
