## Prototype
指定要使用原型实例创建的对象的种类，并通过复制此原型来创建新对象。 
模式具有创造目的，并处理对象关系，动态性更高。 该模式隐藏了从客户端创建新实例的复杂性。
Specify the kinds of objects to create using a prototypical instance, and create 
new objects by copying this prototype. Pattern has creational purpose and deals 
with object relationships, which are more dynamic. The pattern hides the complexities
of making new instances from the client.

### When to use
*在运行时指定要实例化的类时
*避免建立与产品类层次结构平行的工厂类层次结构
*当类的实例只能具有几种不同的状态组合之一时
* when the classes to instantiate are specified at run-time
* to avoid building a class hierarchy of factories that parallels the class hierarchy of products
* when instances of a class can have one of only a few different combinations of state 
