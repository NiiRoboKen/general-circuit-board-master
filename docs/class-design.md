# Class Design

## Diagram

```mermaid
classDiagram

class GCBNode {
    #int id
    #CanDriver& can_driver
    +ping()
    +reset()
    +stop()
}

class CanDriver

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

class GCBSpeedControllableMotor {
    -int id
    -CanDriver& can_driver
    +ping()
    +reset()
    +stop()
    +setRPM(rpm)
}

class GCBServo {
    -int id
    -CanDriver& can_driver
    -MAX_DEGREE
    -MIN_DEGREE
    +ping()
    +reset()
    +stop()
    +setAngle(degree)
}

class GCBRPMEncoder {
    -int id
    -CanDriver& can_driver
    +getRPM()
}

class GCBAngleEncoder {
    -int id
    -CanDriver& can_driver
    +getAngle()
}

class RawMotor {
    <<Interface>>
    +cw(duty)
    +ccw(duty)
    +run(duty)
}

class SpeedControllableMotor {
    <<Interface>>
    +setRPM(rpm)
}

class Servo {
    <<Interface>>
    #MAX_DEGREE
    #MIN_DEGREE
    +setAngle()
}

class RPMEncoder {
    <<Interface>>
    +getRPM()
}

class AngleEncoder {
    <<Interface>>
    +getAngle()
}

GCBRawMotor --|> GCBNode
GCBRawMotor --o CanDriver
GCBRawMotor --|> RawMotor
GCBSpeedControllableMotor --|> GCBNode
GCBSpeedControllableMotor --o CanDriver
GCBSpeedControllableMotor --|> SpeedControllableMotor
GCBServo --|> GCBNode
GCBServo --o CanDriver
GCBServo --|> Servo
GCBRPMEncoder --|> GCBNode
GCBRPMEncoder --o CanDriver
GCBRPMEncoder --|> RPMEncoder
GCBAngleEncoder --|> GCBNode
GCBAngleEncoder --o CanDriver
GCBAngleEncoder --|> AngleEncoder

```

## Explain

### GCBNode

汎用基板を用いたクラスの基底クラス。idとCanDriverへの参照を持つ。

### GCBRawMotor

汎用基板を用いモータをDuty比で制御するクラス。

### GCBSpeedControllabelMotor

汎用基板を用いモータを速度制御するクラス。

### GCBServo

汎用基板を用いモータを角度制御するクラス。

### GCBRPMEncoder

汎用基板から回転速度(rpm)を取得するクラス。

### GCBAngleEncoder

汎用基板から角度を取得するクラス。
