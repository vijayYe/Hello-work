## Factory Method
定义用于创建对象的接口，但让子类决定实例化哪个类。 Factory Method使类将实例化延迟到子类。 
该模式具有创建目的，适用于通过继承即关系处理关系的类。 它们在编译时是静态固定的。 
与Abstract Factory相反，工厂方法包含仅生产一种类型产品的方法。
Define an interface for creating an object, but let subclasses decide which class to instantiate. 
Factory Method lets a class defer instantiation to subclasses. The pattern has creational purpose
and applies to classes where deals with relationships through inheritence ie. they are static-fixed 
at compile time. In contrast to Abstract Factory, Factory Method contain method to produce only one
type of product.  

### When to use
*类无法预期必须创建的对象的类
*类希望其子类指定其创建的对象
*类将责任委派给几个帮助程序子类之一，而您想定位哪个帮助程序子类是委托的知识
* a class cant anticipate the class of objects it must create
* a class wants its subclasses to specify the objects it creates
* classes delegate responsibility to one of several helper subclasses, and you want to localize the knowledge of which helper subclass is the delegate 