# クラス設計

## 前提知識 - クラス図の見方

```mermaid
classDiagram

class ExampleClass {
    + int publicメンバ変数
    # int protectedメンバ変数
    - int privateメンバ変数
    
    + publicメンバ関数() void <- 返り値の型
    # protectedメンバ関数() void
    - priavteメンバ関数() void
}

```

```mermaid
classDiagram

class Menber{
    - int ID
    + getID() int
}
class コンポジション{
    - Menber menbers[]
    + showEveryone() void
}
コンポジション *-- Menber
```

```mermaid
classDiagram

class Manager{
    + SendMessage(char* msg) void
}
class 集約{
    - Manager& manager
    + Send(char* msg) void
}
集約 o-- Manager
```

```mermaid
classDiagram

class Animal {
    <<Interface>>
    + run() void
    + sleep() void
}
class Dog {
    + run() void
    + sleep() void
}
Animal <|-- Dog : 継承
