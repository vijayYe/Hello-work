## Abstract Factory
抽象工厂模式具有创建目的，并提供了一个用于创建相关或依赖对象族的接口，而无需指定其具体类。 
模式适用于对象，并处理更动态的对象关系。 与工厂方法相反，抽象工厂模式会生成相关的类型族。
即。 它具有不止一种类型的产生方法。
Abstract factory pattern has creational purpose and provides an interface for 
creating families of related or dependent objects without specifying their 
concrete classes. Pattern applies to object and deal with object relationships, 
which are more dynamic. In contrast to Factory Method, Abstract Factory pattern
produces family of types that are related, ie. it has more than one method of 
types it produces.


### When to use

*系统应独立于其产品的创建，组成和表示方式
*系统应配置有多个产品系列之一
*相关产品对象系列旨在一起使用
*您想提供产品的类库，并且只想显示它们的接口，而不是它们的实现
* a system should be independent of how its products are created, composed, and represented
* a system should be configured with one of multiple families of products
* a family of related product objects is designed to be used together
* you want to provide a class library of products, and you want to reveal just their interfaces, not their implementations