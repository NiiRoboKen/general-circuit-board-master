# Class Design

## Diagram

```mermaid
classDiagram

class GCBRawMotor {
    -int id
    -CanDriver& can_driver
    +ping()
    +reset()
    +stop()
    +cw(duty)
    +ccw(duty)
    +run(duty)
}

class GCBNode {
    #int id
    #CanDriver& can_driver
    +ping()
    +reset()
    +stop()
}

class RawMotor {
    <<Interface>>
    +cw(duty)
    +ccw(duty)
    +run(duty)
}

GCBRawMotor --|> GCBNode
GCBRawMotor --o CanDriver
GCBRawMotor --|> RawMotor
```

```mermaid
classDiagram
class GCBSpeedControllableMotor {
    -int id
    -CanDriver& can_driver
    +ping()
    +reset()
    +stop()
    +setRPM(rpm)
    +getRPM()
}

class GCBNode {
    #int id
    #CanDriver& can_driver
    +ping()
    +reset()
    +stop()
}

class SpeedControllableMotor {
    <<Interface>>
    +setRPM(rpm)
}

class RPMEncoder {
    <<Interface>>
    +getRPM()
}

GCBSpeedControllableMotor --|> GCBNode
GCBSpeedControllableMotor --o CanDriver
GCBSpeedControllableMotor --|> SpeedControllableMotor
GCBSpeedControllableMotor --|> RPMEncoder
```

```mermaid
classDiagram

class GCBServo {
    -int id
    -CanDriver& can_driver
    -MAX_DEGREE
    -MIN_DEGREE
    +ping()
    +reset()
    +stop()
    +setAngle(degree)
    +getAngle()
}

class GCBNode {
    #int id
    #CanDriver& can_driver
    +ping()
    +reset()
    +stop()
}

class Servo {
    <<Interface>>
    #MAX_DEGREE
    #MIN_DEGREE
    +setAngle()
}

class AngleEncoder {
    <<Interface>>
    +getAngle()
}

GCBServo --|> GCBNode
GCBServo --o CanDriver
GCBServo --|> Servo
GCBServo --|> AngleEncoder
```

```mermaid
classDiagram

class GCBEncoder {
    -int id
    -CanDriver& can_driver
    +getRPM()
    +getAngle()
}

class GCBNode {
    #int id
    #CanDriver& can_driver
    +ping()
    +reset()
    +stop()
}

class RPMEncoder {
    <<Interface>>
    +getRPM()
}

class AngleEncoder {
    <<Interface>>
    +getAngle()
}

GCBEncoder --|> GCBNode
GCBEncoder --o CanDriver
GCBEncoder --|> RPMEncoder
GCBEncoder --|> AngleEncoder
```

## Explain

### GCBNode

汎用基板を用いたクラスの基底クラス。idとCanDriverへの参照を持つ。

### GCBRawMotor

汎用基板を用いモータをDuty比で制御するクラス。

### GCBSpeedControllabelMotor

汎用基板を用いモータを速度制御するクラス。

回転速度を取得可能。

### GCBServo

汎用基板を用いモータを角度制御するクラス。

角度を取得可能。

### GCBEncoder

汎用基板から回転速度(rpm)及び角度を取得するクラス。
