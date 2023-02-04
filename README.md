# 紅い部屋からの脱出

ゲームクリエイター科1年　竹林悠斗

# ・作品概要
主人公が、謎を解いたりアイテムを使用したりして
紅い部屋からの脱出を試みるゲームです。

## ・使用エンジン

学校内製エンジン


## ・使用ツール

Visual Studio 2022

3ds Max 2023

Adobe Photoshop(Elements 2020)


## ・使用言語

 C++


## ・開発環境

Windows11


## ・制作人数

1人


## ・開発期間

2022年7月～2023年11月

# ・操作説明
左スティック:カーソルの移動

Aボタン:調べる

Bボタン:戻る

十字キー左右:視点の左右移動

十字キー上下:アイテム変更

Xボタン:操作の表示

Yボタン:ヒントの表示

# ・参考にした物
東方プロジェクトの「東方紅魔郷」の各ボスの特徴を自分なりに考えて、謎やヒントにしてみました。

# ・苦労した点
## ・ヒントの表示

謎が今どの程度解けているのかを変数で判定してヒントを表示するようにした。


	switch (game->levelb)
	{
	case 0:
		spriteRender.Init("Assets/sprite/hint1.DDS", 1920.0f, 1080.0f);
		break;
	case 1:
		if (game->levela < 2)
		{
            spriteRender.Init("Assets/sprite/hint2.DDS", 1920.0f, 1080.0f);
        …

## ・ダイヤルを変えて数字や文字をそろえる系統の謎

ダイヤルがどの数字や文字を表示するかを、専用の変数を変えることで、
Switch文で判断、表示をするようにした。

    switch (k1select)
		{
		case 0:
			spriteRender.Init("Assets/sprite/dial.gr.DDS", 200.0f, 300.0f);
			k1word = k1select;
			spriteRender.SetPosition(positiond1);
			spriteRender.Update();
			break;
		case 1:
        …

## ・背景
3dsMaxでオブジェクトを配置、レンダリングしたものを画像として保存し、自分の見ている場所に応じて切り替えて表示している。

# ・次から気を付けたい点
もう少し簡潔で見やすいプログラムを書きたい。