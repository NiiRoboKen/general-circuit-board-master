# General Circuit Board Master Protocol

CAN通信ででf303k8の汎用基盤に命令する通信プロトコルを書きます。

## ID
### 特徴
```
| Command (11bit) | Sender id (8bit) | Receiver id (8bit) | Motor number (2bit) |
```
- 拡張ID(`29bit`)で送信
- `Command`には`13bit`の命令が入る
- `Sender id`には`8bit`で送り元のIDが入る
- `Receiver id`には`8bit`で送り先のIDが入る
- `Motor number`には基盤のどちらの出力を扱うかを指定
    - `00`: 指定なし(STMからESPへの送信の場合)
    - `01`: 出力1番
    - `10`: 出力2番
    - `11`: 両方指定

### Command

| コマンド名             | データ           | 説明                      |
| -------------------- | --------------- | -----------------------  |
| STOP                 | 0x0000          | 全ての機能を停止            |
| RESET                | 0x0001          | 全ての設定をリセット         |
| PING                 | 0x0002          | 疎通確認                  |
| PONG                 | 0x0003          | 疎通確認の返事             |
| ERROR                | 0x0004          | エラー通知                 |
| SET CONFIG           | 0x0010          | 基盤の設定                |
| SET PID GAIN (ANGLE) | 0x0011          | 角度PIDのゲイン設定        |
| SET PID GAIN (RPM)   | 0x0012          | 速度PIDのゲイン設定        |
| SET ANGLE            | 0x0101          | 角度の目標値を指定         |
| SET RPM              | 0x0102          | RPMの目標値を指定         |
| SET DUTY             | 0x0103          | Duty比を指定             |
| REQUEST GET ANGLE    | 0x0111          | 現在の角度をリクエスト      |
| REQUEST GET RPM      | 0x0112          | 現在の速度をリクエスト      |
| RETURN GET ANGLE     | 0x0121          | 現在の角度を返す           |
| RETURN GET RPM       | 0x0122          | 現在の速度を返す           |

## DATA
### 概要
- データの内容は`Command`に依る

#### STOP
```
||
```
#### RESET
```
||
```
#### PING
```
||
```
#### PONG
```
||
```
#### ERROR
```
||
```
#### SET CONFIG
```
| CONTROL CONFIG (1byte) | SELECT SWITCH (1byte) | SWITCH CONFIG (1byte) | 
```
##### CONTROL CONFIG (1byte) 
- angle_pid `0x01`
- speed_pid `0x02`
- duty_control `0x03`

##### SELECT SWITCH (1byte)
- On `0x00`
- Off `0x01`

##### SWITCH CONFIG (1byte)
- disable-cw　`0x01`
- disable-ccw　`0x02`
- reset-current-value `0x05`

#### SET PID GAIN (ANGLE)
```
| P GAIN (2byte) | I GAIN (2byte) | D GAIN (4byte) |
```
- `P GAIN`、`I GAN` には自然数を入れる
- `D GAIN`には小数点第三位までの数値を1000倍した値を入れる
#### SET PID GAIN (RPM)
```
| P GAIN (2byte) | I GAIN (2byte) | D GAIN (4byte) |
```
- `SET PID GAIN (ANGLE)`と同様
#### SET ANGLE
```
| is CW (1byte) | VALUE (2byte) |
```
- `is CW`には`CW`なら`1`、`CCW`なら`0`を入れる
- `VALUE`には単位が°の角度を入れる。（正の値、自然数）
#### SET RPM
```
| is CW (1byte) | VALUE (2byte) |
```
- `is CW`には`CW`なら`1`、`CCW`なら`0`を入れる
- `VALUE`にはRPMを入れる(自然数)
#### SET DUTY
```
| is CW (1byte) | DUTY (1byte) |
```
- `is CW`には`CW`なら`1`、`CCW`なら`0`を入れる
- `DUTY`には`0`から`100`までの値を入れる(自然数)
#### REQUEST GET ANGLE 
```
||
```
#### REQUEST GET RPM
```
||
```
#### RETURN ANGLE
```
| is CW (1byte) | VALUE (2byte) |
```
- `SET ANGLE`と同様
#### RETURN RPM
```
| is CW (1byte) | VALUE (2byte) |
```
- `SET RPM`と同様