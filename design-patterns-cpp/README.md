## C++ Design Patterns

软件设计模式是针对在面向对象设计环境中反复发生的问题的通用可重用解决方案。
这不是可以直接转换为源代码的最终设计，而是解决问题的模板。
我们可以按目的将它们分为创建性（抽象实例化过程），结构（如何将类和对象组成更大的结构）和行为模式（对象之间的职责分配）。
Software design patterns are general reusable solutions to problems which occur
over and over again in object-oriented design enviroment. It is not a finished 
design that can be transformed into source code directly, but it is template how
to solve the problem. We can classify them by purpose into creational (abstract 
the instantiation process), structure (how classes and objects are composed to form 
larger structures) and behavioral patterns (the assignment of responsibilities between 
objects).  

####创作模式
-[抽象工厂]，产品对象族
-[Builder]，如何创建复合对象
-[工厂方法]，实例化的对象的子类
-[原型]，实例化的对象类
-[Singleton]，一个类的唯一实例
#### Creational Patterns 
- [Abstract Factory], families of product objects
- [Builder], how a composite object gets created
- [Factory Method], subclass of object that is instantiated
- [Prototype], class of object that is instantiated
- [Singleton], the sole instance of a class 

####结构模式
-[适配器]，对象的接口
-[桥]，实现一个对象
-[复合]，对象的结构和组成
-[装饰器]，不带子类的对象的责任
-[外观]，连接至子系统
-[Flyweight]，对象的存储成本
-[代理]，如何访问对象（其位置）
#### Structural Patterns
- [Adapter], interface to an object
- [Bridge], implementation of an object 
- [Composite], structure and composition of an object
- [Decorator], responsibilities of an object without subclassing
- [Façade], interface to a subsystem
- [Flyweight], storage costs of objects
- [Proxy], how an object is accessed (its location)

####行为模式
-[责任链]，可以满足请求的对象
-[命令]，何时以及如何满足请求
-[口译]，语言的语法和解释
-[迭代器]，如何访问集合的元素
-[介体]，对象之间如何以及如何交互
-[Memento]，什么私有信息存储在对象外部，以及何时
-[观察者]，相关对象如何保持最新
-[状态]，对象的状态
-[策略]，一种算法
-[模板方法]，算法步骤
-[访问者]，可以在不更改其类的情况下应用于对象的操作
#### Behavioral Patterns
- [Chain of Responsibility], object that can fulfill a request
- [Command], when and how a request is fulfilled
- [Interpreter], grammar and interpretation of a language
- [Iterator], how an aggregate's elements are accessed
- [Mediator], how and which objects interact with each other
- [Memento], what private information is stored outside an object, and when 
- [Observer], how the dependent objects stay up to date
- [State], states of an object
- [Strategy], an algorithm
- [Template Method], steps of an algorithm
- [Visitor], operations that can be applied to objects without changing their classes

###其他语言
在我的存储库中，您还可以在以下语言中找到设计模式的实现：
### Other Languages
In my repository you can find implementation of desgin patterns also in languages as 

* [Design Patterns in C++]
* [Design Patterns in Java]
* [Design Patterns in Python]

### References
Design patterns in this repository are based on

* [Design Patterns by The "Gang of Four"]
* [Head First: Design Patterns]
* [Wikipedia]

[Design Patterns in C++]: https://github.com/JakubVojvoda/design-patterns-cpp
[Design Patterns in Java]: https://github.com/JakubVojvoda/design-patterns-java
[Design Patterns in Python]: https://github.com/JakubVojvoda/design-patterns-python

[Design Patterns by The "Gang of Four"]: https://en.wikipedia.org/wiki/Design_Patterns
[Head First: Design Patterns]: http://www.headfirstlabs.com/books/hfdp/ 
[Wikipedia]: https://en.wikipedia.org/wiki/Software_design_pattern

[Abstract Factory]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/abstract-factory
[Builder]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/builder
[Factory Method]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/factory-method
[Prototype]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/prototype
[Singleton]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/singleton
[Adapter]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/adapter
[Bridge]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/bridge 
[Composite]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/composite
[Decorator]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/decorator
[Façade]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/facade
[Flyweight]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/flyweight
[Proxy]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/proxy
[Chain of Responsibility]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/chain-of-responsibility
[Command]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/command
[Interpreter]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/interpreter
[Iterator]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/iterator
[Mediator]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/mediator
[Memento]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/memento
[Observer]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/observer
[State]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/state
[Strategy]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/strategy
[Template Method]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/template-method
[Visitor]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/visitor
