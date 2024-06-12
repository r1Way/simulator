# 初级版本

## api

![event](G:\inspiration\simulator\photos\event.png)

### <mark>MapNode<mark>

为结点，提供图的结构

#### T data

数据

#### vector< MapNode> from

记录信号从哪来

#### vector<MapNode*> to_ptr

记录信号要去哪



#### <mark>Map<mark>



### <mark>Element<mark>

为某个接口

#### int value

为其值

#### int delay

#### setValue()

设置自己的值

#### getValue()

获取自己的值



### <marK>Gate<mark>
门与各种元件的统称

#### vector< Element > in

各个输入接口

#### vector< Element > out

各个输出接口

#### enum

列举各接口名称

#### vector< vector< int>>  delay

二维数组，描述了in到out



### <mark>Event<mark>

记录各个输入值的更改,更改亦有先后,通过List进行管理，组成EventList

#### vector<Element *> elements_ptr

记录更改的Element

#### vector< int > values


记录对应更改的值




### <mark>Time<mark>

为时间表，记录有驱动事件的时间，通过List进行管理

#### int time

记录此时的时间

#### list< Event>* events_ptr

记录该时间的事件链



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


### <mark>全局函数<mark>

update(EventNode& );

更新event对应element的状况，以及element对应Gate的状况，并将新的状况插入到对应TimeNode的events_ptr中
