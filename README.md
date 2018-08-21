# GR-CITRUS mruby Arduino API (wrbb-v2lib-firm)

GR-CITRUSは「[がじぇるね](http://gadget.renesas.com/ja/)」のボードで、Ruby言語でArduino APIが使用できる[ファームウェア](https://github.com/wakayamarb/wrbb-v2lib-firm)が利用できます。このプロジェクトでは、Rubyの実装部分[mruby](https://github.com/mruby/mruby)が使用するメモリのうち、初期化直後に状態をROMに割り当てることで、ユーザーが使用できるメモリを増やすための対策を行いました。  
GR-CITRUSよりもメモリ容量が少ないGR-SAKURAでも動作し、Ethernetが使えるようRTOSの[TOPPERS/ASP](https://www.toppers.jp/asp-kernel.html)とプロトコルスタックの[TINET](http://www.toppers.jp/tinet.html)を追加しました。また、[ECHONET Lite](https://echonet.jp/)の通信ができるよう、mrubyの拡張機能[mruby版ECNL](https://github.com/h7ga40/mruECNL)が含まれています。

## ビルド

ビルドはWindows用統合環境の[e2studio](https://www.renesas.com/jp/ja/products/software-tools/tools/ide/e2studio.html)と[RX用GCC](https://gcc-renesas.com/ja/)を使用します。また、mrubyのビルドに[Rubyの実行環境](https://www.ruby-lang.org/ja/downloads/)が必要なので、インストールしてください。  
このe2studioでREADMEがあるフォルダをワークスペースとして開き、インポートでこのフォルダを選択することで、必要なプロジェクトが追加されます。

|フォルダ|概要|プロジェクトの種類|
--|--|--
|wrbb-v2lib-firm|Arduino Ruby API|統合環境でビルド（CitrusとSakuraのビルド構成あり）|
|mruby-1.4.1|mruby|./minirakeでビルドし./buildに出力|
|mrbgems|mrubyの拡張機能|フォルダ|
|asp|RTOSとプロトコルスタック|./Debug/Makefileでビルド|
|tools|ビルド用ツール|フォルダ|
|citrus_sketch|GR-CITRUS向けメイン|./Debug/Makefileでビルド|
|sakura_sketch|GR-SAKURA向けメイン|./Debug/Makefileでビルド|

## mrubyの省RAM化対策について

mrubyの初期化直後の動的メモリの状態をGCがマークする要領でオブジェクトを辿り、[preset_symbols.cpp](https://github.com/h7ga40/gr_citrus/citrus_sketch/blob/master/src/preset_symbols.cpp)としてコードにダンプしました。
ダンプするプログラムのコードは[ここ](https://github.com/h7ga40/BlocklyMruby/blob/master/msvc/mruby/objdump.c)にあります。  
Rubyのクラス定義や文字列などの変化のないデータをROMに割り当てることで、RAMの使用量を減らしています。クラス定義でもインスタンス変数やメソッドは実行時に追加されるので、それらを収めるハッシュテーブルはRAMに割り当てていますが、初期化動作はROMからのコピーになるので、起動が早くなっていると思います。
GCの動作などで、予め割り当てたメモリか実行時に追加したメモリかを区別する必要があるので、mruby本体にも変更を行っています。

## GR-SAKURA向け省RAM化

wrbb-v2lib-firmでは、GR-CITRUSの内蔵DATA ROMをファイルシステムで利用していますが、GR-SAKURAではファイルシステムはSDカードのみで、内蔵DATA ROMにコンパイルしたmrubyのプログラムが入ります。GR-CITRUSではmrubyのプログラムはRAMに展開されるので、その分のRAM容量を確保しています。

## ライセンス

いくつかのソフトウェアを組み合させて作っていますので、各ソフトウェアのライセンスに従ってください。

|ソフト|ライセンス|
--|--
|wrbb-v2lib-firm|MIT, LGPL|
|mruby|MIT|
|TOPPERS/ASP|TOPPERSライセンス(BSDに近いライセンス)|
|TINET|TOPPERSライセンス(BSDに近いライセンス)|

## 注意

このプロジェクトは、mrubyの省RAM化など実験的で十分に検証していないコードが含まれています。
