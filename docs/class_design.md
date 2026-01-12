# クラス設計

## クラス図

```mermaid
classDiagram

class GCBMotor {
    +runDuty(dir, duty)
    -node_id
    -CanDriver&
}
class GCBPIDMotor {
    +runDuty(dir, duty)
    +run(dir, rpm)
    +getRPM()
    -node_id
    -CanDriver&
    -PIDgain
}
class GCBPIDServo {
    +setAngle(angle)
    +getAngle()
    -node_id
    -CanDriver&
    -PIDgain
}

class Motor {
    <<Interface>>
    +runDuty(dir, duty)
}
class EncordableMotor {
    <<Interface>>
    +runDuty(dir, duty)
    +run(dir, rpm)
    +getRPM()
}
class Servo {
    <<Interface>>
    +setAngle(angle)
}
class EncordableServo {
    <<Interface>>
    +setAngle(angle)
    +getAngle(angle)
}
class GCBnode {
    #node_id
    #CanDriver&
    +ping() bool
    +stop()
    +reboot()
    #send(command, val)
}

GCBMotor --|> Motor
GCBMotor --|> GCBnode
GCBPIDMotor --|> EncordableMotor
GCBPIDMotor --|> GCBnode
GCBPIDServo --|> EncordableServo
GCBPIDServo --|> GCBnode
EncordableMotor --|> Motor
EncordableServo --|> Servo
CanDriver --o GCBMotor
CanDriver --o GCBPIDMotor
CanDriver --o GCBPIDServo
```

## 説明

### 汎用基板モータクラス(GCBMotor)

#### GCBMotor-機能

汎用基板を使用しDCモータをdutyでフィードフォワード制御します。

#### GCBMotor-継承関係

DCモータをdutyで制御するのでMotorクラスを継承します。

汎用基板を使用するのでGCBnodeクラスを継承します。

#### GCBMotor-集約/コンポジット関係

汎用基板とのCAN通信のためCanDriverクラスの参照を持ちます。

### 汎用基板PID制御モータクラス(GCBPIDMotor)

#### GCBPIDMotor-機能

汎用基板を使用しDCモータをPIDで速度制御します。

#### GCBPIDMotor-継承関係

DCモータを速度制御しフィードバックを受け取るためEncordableMotorクラスを継承します。

汎用基板を使用するのでGCBnodeクラスを継承します。

#### GCBPIDMotor-集約/コンポジット関係

汎用基板とのCAN通信のためのCanDriverクラスの参照を持ちます。

PID制御のためのゲインを持ちます。

### 汎用基板PID制御サーボクラス(GCBPIDServo)

#### GCBPIDServo-機能

汎用基板を使用しDCモータをPIDで角度制御します。

#### GCBPIDServo-継承関係

DCモータを角度制御しフィードバックを受け取るためEncordableServoクラスを継承します。

汎用基板を使用するのでGCBnodeクラスを継承します。

#### GCBPIDServo-集約/コンポジット関係

汎用基板とのCAN通信のためのCanDriverクラスの参照を持ちます。

PID制御のためのゲインを持ちます。
