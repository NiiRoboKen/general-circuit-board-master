# General Circuit Board Master Protocol

CAN通信ででf303k8の汎用基盤に命令する通信プロトコルを書きます。

## ID
### 特徴
```
| Command (13bit) | Sender id (8bit) | Receiver id (8bit) |
```
- 拡張ID(`29bit`)で送信
- `Command`には`13bit`の命令が入る
- `Sender id`には`8bit`で送り元のIDが入る
- `receiver id`には`8bit`で送り先のIDが入る

### Command

| コマンド名             | データ           | 説明                      |
| -------------------- | --------------- | -----------------------  |
| STOP                 | 0x0000          | 全ての機能を停止            |
| RESET                | 0x0001          | 全ての設定をリセット         |
| PING                 | 0x0002          | 疎通確認                  |
| PONG                 | 0x0003          | 疎通確認の返事             |
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

```
#### RESET
```

```
#### PING
```

```
#### PING
```

```
#### PONG
```

```
#### SET CONFIG
```

```
#### SET PID GAIN (ANGLE)
```

```
#### SET PID GAIN (RPM)
```

```
#### SET ANGLE
```

```
#### SET RPM
```

```
#### SET DUTY
```

```
#### REQUEST GET ANGLE 
```

```
#### REQUEST GET RPM
```

```
#### RETURN ANGLE
```

```
#### RETURN RPM
```

```