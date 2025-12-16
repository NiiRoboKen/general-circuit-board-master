# クラス構成 説明

```mermaid
classDiagram

class CanDriver
```

`esp-can`ライブラリ。CAN通信に使用。

```mermaid
classDiagram

class MotorController{
    <<InterFace>>
    + cw(id, speed)
    + ccw(id, speed)
}
class ServoController{
    <<InterFace>>
    + setAngle(id, angle)
}

class GeneralCircuitBoardsController{
    - CanDriver&

    + setAngle(id, angle)
    + cw(id, speed)
    + ccw(id, speed)
}
GeneralCircuitBoardsController *-- CanDriver
GeneralCircuitBoardsController --|> ServoController
GeneralCircuitBoardsController --|> MotorController
```

汎用基板クラス。汎用基板との通信に`CanDriver`クラスの参照を持つ(集約)。

角度制御が可能であるため`ServoController`インターフェースを継承する。

速度制御が可能であるため`MotorController`インターフェースを継承する。

```mermaid
classDiagram

class Motor{
    - ID
    - MotorController&
    + cw(speed)
    + ccw(speed)
}

class Servo{
    - ID
    - ServoController&
    + setAngle(angle)
}

Motor *-- MotorController
Servo *-- ServoController
```

モータ/サーボをオブジェクトとして扱うためのクラス。それぞれコントローラの参照を持つ(集約)。

コントローラがインタフェースであるため継承によって拡張できる。
