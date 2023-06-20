# 簡易ToDoリスト
簡単なコマンドを使ってToDoリストを管理します.
# 特長
シンプルなコマンドでリストを管理できます.
各作業への時間配分を求めることができます.
# Build & Compile
```
$ git clone https://github.com/motncucya/myScheduler.git
$ cd myScheduler
$ export CXXFLAGS="-std=c++17"
$ make
```
# Start
```
$ ./myScheduler
```
# 予定の追加
```
add 件名 時間 優先度
```
## 予定の変更
```
set 件名 時間 優先度
```
## 予定の削除
```
del 件名
```
## 予定の確認
```
get 件名
```
## 予定一覧
```
print
```
## 終了
```
quit
```
## スケジューリング 
作業時間に予定の優先度のシェアを乗じて、その予定に割ける時間を求めます.
```
$ schedule
```

# 実行例
```
input "help" to get information
> add test 0 10
> add test2 0 20
> schedule
test2 5.33333h
test 2.66667h
> get test
test 0 10
> get test2
test2 0 20
> set test 0 20
> schedule
test 4h
test2 4h
> quit
```
