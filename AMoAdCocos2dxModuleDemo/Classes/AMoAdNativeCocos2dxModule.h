//
//  AMoAdNativeCocos2dxModule.h
//
//  Created by AMoAd on 2016/02/01.
//
#ifndef __AMoAdNativeCocos2dxModule__
#define __AMoAdNativeCocos2dxModule__

#include "cocos2d.h"

/// Cocos2d-xにAMoAdを表示するクラス
/// すべてクラスメソッドなのでインスタンスを生成する必要はありません。
class AMoAdNativeCocos2dxModule {
private:
  /// インスタンスを生成する必要はありません
  AMoAdNativeCocos2dxModule();
public:
  /// モジュールバージョン
  static constexpr char const* VersionNo = "1.0.2";


  /// 広告をロードする
  /// @param sid 管理画面から取得した64文字の英数字
  /// @param tag 同じsidを複数のビューで使用するときの識別子<br />任意の文字列を指定できます
  /// @param x 広告のX座標
  /// @param y 広告のY座標
  /// @param width 広告の横幅
  /// @param height 広告の縦幅
  static void load(const char* sid, const char* tag, int x, int y, int width, int height);

  /// 広告Viewを削除する（親ビューからremoveされます）
  /// @param sid 管理画面から取得した64文字の英数字
  /// @param tag 同じsidを複数のビューで使用するときの識別子<br />任意の文字列を指定できます
  static void remove(const char* sid, const char* tag);

  /// 広告をリロード（別の広告に更新）する
  /// @param sid 管理画面から取得した64文字の英数字
  /// @param tag 同じsidを複数のビューで使用するときの識別子<br />任意の文字列を指定できます
  static void reload(const char* sid, const char* tag);

  /// 広告Viewを表示する
  /// @param sid 管理画面から取得した64文字の英数字
  /// @param tag 同じsidを複数のビューで使用するときの識別子<br />任意の文字列を指定できます
  static void show(const char* sid, const char* tag);

  /// 広告Viewを非表示にする
  /// @param sid 管理画面から取得した64文字の英数字
  /// @param tag 同じsidを複数のビューで使用するときの識別子<br />任意の文字列を指定できます
  static void hide(const char* sid, const char* tag);

  /// ローテーションを開始する
  /// @param sid 管理画面から取得した64文字の英数字
  /// @param tag 同じsidを複数のビューで使用するときの識別子<br />任意の文字列を指定できます
  /// @param seconds ローテーション間隔（秒）
  static void startRotation(const char* sid, const char* tag, int seconds);

  /// ローテーションを停止する
  /// @param sid 管理画面から取得した64文字の英数字
  /// @param tag 同じsidを複数のビューで使用するときの識別子<br />任意の文字列を指定できます
  static void stopRotation(const char* sid, const char* tag);

  /// 開発用
  /// @param htmlUrlString
  static void setHtmlUrlString(const char* htmlUrlString);

  /// 開発用
  /// @param sid 管理画面から取得した64文字の英数字
  /// @param tag 同じsidを複数のビューで使用するときの識別子<br />任意の文字列を指定できます
  /// @param x 広告のX座標
  /// @param y 広告のY座標
  /// @param width 広告の横幅
  /// @param height 広告の縦幅
  /// @param option 開発用
  static void load(const char* sid, const char* tag, int x, int y, int width, int height, const char* option);

};

#endif  // __AMoAdNativeCocos2dxModule__
