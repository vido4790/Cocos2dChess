# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.Chess.Debug:
PostBuild.cocos2d.Debug: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Debug/Chess.app/Contents/MacOS/Chess
PostBuild.external.Debug: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Debug/Chess.app/Contents/MacOS/Chess
PostBuild.ext_recast.Debug: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Debug/Chess.app/Contents/MacOS/Chess
PostBuild.ext_tinyxml2.Debug: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Debug/Chess.app/Contents/MacOS/Chess
PostBuild.ext_xxhash.Debug: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Debug/Chess.app/Contents/MacOS/Chess
PostBuild.ext_xxtea.Debug: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Debug/Chess.app/Contents/MacOS/Chess
PostBuild.ext_clipper.Debug: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Debug/Chess.app/Contents/MacOS/Chess
PostBuild.ext_edtaa3func.Debug: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Debug/Chess.app/Contents/MacOS/Chess
PostBuild.ext_convertUTF.Debug: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Debug/Chess.app/Contents/MacOS/Chess
PostBuild.ext_poly2tri.Debug: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Debug/Chess.app/Contents/MacOS/Chess
PostBuild.ext_md5.Debug: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Debug/Chess.app/Contents/MacOS/Chess
PostBuild.ext_unzip.Debug: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Debug/Chess.app/Contents/MacOS/Chess
/Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Debug/Chess.app/Contents/MacOS/Chess:\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libcocos2d.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libexternal.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/Box2D/prebuilt/mac/libbox2d.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/chipmunk/prebuilt/mac/libchipmunk.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/freetype2/prebuilt/mac/libfreetype.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_recast.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libBulletDynamics.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libBulletCollision.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libBulletMultiThreaded.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libMiniCL.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/jpeg/prebuilt/mac/libjpeg.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/webp/prebuilt/mac/libwebp.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/websockets/prebuilt/mac/libwebsockets.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/openssl/prebuilt/mac/libssl.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/openssl/prebuilt/mac/libcrypto.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/uv/prebuilt/mac/libuv_a.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_tinyxml2.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_xxhash.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_xxtea.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_clipper.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_edtaa3func.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_convertUTF.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_poly2tri.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_md5.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/curl/prebuilt/mac/libcurl.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/png/prebuilt/mac/libpng.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glfw3/prebuilt/mac/libglfw3.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/zlib/prebuilt/mac/libz.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_unzip.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glsl-optimizer/prebuilt/mac/libglcpp-library.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glsl-optimizer/prebuilt/mac/libglsl_optimizer.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glsl-optimizer/prebuilt/mac/libmesa.a\
	/usr/lib/libiconv.dylib
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Debug/Chess.app/Contents/MacOS/Chess


PostBuild.ChessTests.Debug:
/Users/viragdoshi/dev/git/personal/Chess/bin/Debug/ChessTests:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/bin/Debug/ChessTests


PostBuild.cocos2d.Debug:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libcocos2d.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libcocos2d.a


PostBuild.ext_clipper.Debug:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_clipper.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_clipper.a


PostBuild.ext_convertUTF.Debug:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_convertUTF.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_convertUTF.a


PostBuild.ext_edtaa3func.Debug:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_edtaa3func.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_edtaa3func.a


PostBuild.ext_md5.Debug:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_md5.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_md5.a


PostBuild.ext_poly2tri.Debug:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_poly2tri.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_poly2tri.a


PostBuild.ext_recast.Debug:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_recast.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_recast.a


PostBuild.ext_tinyxml2.Debug:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_tinyxml2.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_tinyxml2.a


PostBuild.ext_unzip.Debug:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_unzip.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_unzip.a


PostBuild.ext_xxhash.Debug:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_xxhash.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_xxhash.a


PostBuild.ext_xxtea.Debug:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_xxtea.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_xxtea.a


PostBuild.external.Debug:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libexternal.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libexternal.a


PostBuild.Chess.Release:
PostBuild.cocos2d.Release: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Release/Chess.app/Contents/MacOS/Chess
PostBuild.external.Release: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Release/Chess.app/Contents/MacOS/Chess
PostBuild.ext_recast.Release: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Release/Chess.app/Contents/MacOS/Chess
PostBuild.ext_tinyxml2.Release: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Release/Chess.app/Contents/MacOS/Chess
PostBuild.ext_xxhash.Release: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Release/Chess.app/Contents/MacOS/Chess
PostBuild.ext_xxtea.Release: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Release/Chess.app/Contents/MacOS/Chess
PostBuild.ext_clipper.Release: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Release/Chess.app/Contents/MacOS/Chess
PostBuild.ext_edtaa3func.Release: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Release/Chess.app/Contents/MacOS/Chess
PostBuild.ext_convertUTF.Release: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Release/Chess.app/Contents/MacOS/Chess
PostBuild.ext_poly2tri.Release: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Release/Chess.app/Contents/MacOS/Chess
PostBuild.ext_md5.Release: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Release/Chess.app/Contents/MacOS/Chess
PostBuild.ext_unzip.Release: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Release/Chess.app/Contents/MacOS/Chess
/Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Release/Chess.app/Contents/MacOS/Chess:\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libcocos2d.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libexternal.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/Box2D/prebuilt/mac/libbox2d.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/chipmunk/prebuilt/mac/libchipmunk.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/freetype2/prebuilt/mac/libfreetype.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_recast.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libBulletDynamics.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libBulletCollision.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libBulletMultiThreaded.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libMiniCL.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/jpeg/prebuilt/mac/libjpeg.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/webp/prebuilt/mac/libwebp.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/websockets/prebuilt/mac/libwebsockets.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/openssl/prebuilt/mac/libssl.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/openssl/prebuilt/mac/libcrypto.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/uv/prebuilt/mac/libuv_a.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_tinyxml2.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_xxhash.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_xxtea.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_clipper.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_edtaa3func.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_convertUTF.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_poly2tri.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_md5.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/curl/prebuilt/mac/libcurl.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/png/prebuilt/mac/libpng.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glfw3/prebuilt/mac/libglfw3.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/zlib/prebuilt/mac/libz.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_unzip.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glsl-optimizer/prebuilt/mac/libglcpp-library.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glsl-optimizer/prebuilt/mac/libglsl_optimizer.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glsl-optimizer/prebuilt/mac/libmesa.a\
	/usr/lib/libiconv.dylib
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/Release/Chess.app/Contents/MacOS/Chess


PostBuild.ChessTests.Release:
/Users/viragdoshi/dev/git/personal/Chess/bin/Release/ChessTests:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/bin/Release/ChessTests


PostBuild.cocos2d.Release:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libcocos2d.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libcocos2d.a


PostBuild.ext_clipper.Release:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_clipper.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_clipper.a


PostBuild.ext_convertUTF.Release:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_convertUTF.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_convertUTF.a


PostBuild.ext_edtaa3func.Release:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_edtaa3func.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_edtaa3func.a


PostBuild.ext_md5.Release:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_md5.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_md5.a


PostBuild.ext_poly2tri.Release:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_poly2tri.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_poly2tri.a


PostBuild.ext_recast.Release:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_recast.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_recast.a


PostBuild.ext_tinyxml2.Release:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_tinyxml2.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_tinyxml2.a


PostBuild.ext_unzip.Release:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_unzip.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_unzip.a


PostBuild.ext_xxhash.Release:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_xxhash.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_xxhash.a


PostBuild.ext_xxtea.Release:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_xxtea.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_xxtea.a


PostBuild.external.Release:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libexternal.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libexternal.a


PostBuild.Chess.MinSizeRel:
PostBuild.cocos2d.MinSizeRel: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/MinSizeRel/Chess.app/Contents/MacOS/Chess
PostBuild.external.MinSizeRel: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/MinSizeRel/Chess.app/Contents/MacOS/Chess
PostBuild.ext_recast.MinSizeRel: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/MinSizeRel/Chess.app/Contents/MacOS/Chess
PostBuild.ext_tinyxml2.MinSizeRel: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/MinSizeRel/Chess.app/Contents/MacOS/Chess
PostBuild.ext_xxhash.MinSizeRel: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/MinSizeRel/Chess.app/Contents/MacOS/Chess
PostBuild.ext_xxtea.MinSizeRel: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/MinSizeRel/Chess.app/Contents/MacOS/Chess
PostBuild.ext_clipper.MinSizeRel: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/MinSizeRel/Chess.app/Contents/MacOS/Chess
PostBuild.ext_edtaa3func.MinSizeRel: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/MinSizeRel/Chess.app/Contents/MacOS/Chess
PostBuild.ext_convertUTF.MinSizeRel: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/MinSizeRel/Chess.app/Contents/MacOS/Chess
PostBuild.ext_poly2tri.MinSizeRel: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/MinSizeRel/Chess.app/Contents/MacOS/Chess
PostBuild.ext_md5.MinSizeRel: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/MinSizeRel/Chess.app/Contents/MacOS/Chess
PostBuild.ext_unzip.MinSizeRel: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/MinSizeRel/Chess.app/Contents/MacOS/Chess
/Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/MinSizeRel/Chess.app/Contents/MacOS/Chess:\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libcocos2d.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libexternal.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/Box2D/prebuilt/mac/libbox2d.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/chipmunk/prebuilt/mac/libchipmunk.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/freetype2/prebuilt/mac/libfreetype.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_recast.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libBulletDynamics.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libBulletCollision.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libBulletMultiThreaded.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libMiniCL.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/jpeg/prebuilt/mac/libjpeg.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/webp/prebuilt/mac/libwebp.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/websockets/prebuilt/mac/libwebsockets.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/openssl/prebuilt/mac/libssl.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/openssl/prebuilt/mac/libcrypto.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/uv/prebuilt/mac/libuv_a.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_tinyxml2.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_xxhash.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_xxtea.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_clipper.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_edtaa3func.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_convertUTF.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_poly2tri.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_md5.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/curl/prebuilt/mac/libcurl.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/png/prebuilt/mac/libpng.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glfw3/prebuilt/mac/libglfw3.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/zlib/prebuilt/mac/libz.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_unzip.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glsl-optimizer/prebuilt/mac/libglcpp-library.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glsl-optimizer/prebuilt/mac/libglsl_optimizer.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glsl-optimizer/prebuilt/mac/libmesa.a\
	/usr/lib/libiconv.dylib
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/MinSizeRel/Chess.app/Contents/MacOS/Chess


PostBuild.ChessTests.MinSizeRel:
/Users/viragdoshi/dev/git/personal/Chess/bin/MinSizeRel/ChessTests:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/bin/MinSizeRel/ChessTests


PostBuild.cocos2d.MinSizeRel:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libcocos2d.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libcocos2d.a


PostBuild.ext_clipper.MinSizeRel:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_clipper.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_clipper.a


PostBuild.ext_convertUTF.MinSizeRel:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_convertUTF.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_convertUTF.a


PostBuild.ext_edtaa3func.MinSizeRel:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_edtaa3func.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_edtaa3func.a


PostBuild.ext_md5.MinSizeRel:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_md5.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_md5.a


PostBuild.ext_poly2tri.MinSizeRel:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_poly2tri.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_poly2tri.a


PostBuild.ext_recast.MinSizeRel:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_recast.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_recast.a


PostBuild.ext_tinyxml2.MinSizeRel:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_tinyxml2.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_tinyxml2.a


PostBuild.ext_unzip.MinSizeRel:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_unzip.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_unzip.a


PostBuild.ext_xxhash.MinSizeRel:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_xxhash.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_xxhash.a


PostBuild.ext_xxtea.MinSizeRel:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_xxtea.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_xxtea.a


PostBuild.external.MinSizeRel:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libexternal.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libexternal.a


PostBuild.Chess.RelWithDebInfo:
PostBuild.cocos2d.RelWithDebInfo: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/RelWithDebInfo/Chess.app/Contents/MacOS/Chess
PostBuild.external.RelWithDebInfo: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/RelWithDebInfo/Chess.app/Contents/MacOS/Chess
PostBuild.ext_recast.RelWithDebInfo: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/RelWithDebInfo/Chess.app/Contents/MacOS/Chess
PostBuild.ext_tinyxml2.RelWithDebInfo: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/RelWithDebInfo/Chess.app/Contents/MacOS/Chess
PostBuild.ext_xxhash.RelWithDebInfo: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/RelWithDebInfo/Chess.app/Contents/MacOS/Chess
PostBuild.ext_xxtea.RelWithDebInfo: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/RelWithDebInfo/Chess.app/Contents/MacOS/Chess
PostBuild.ext_clipper.RelWithDebInfo: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/RelWithDebInfo/Chess.app/Contents/MacOS/Chess
PostBuild.ext_edtaa3func.RelWithDebInfo: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/RelWithDebInfo/Chess.app/Contents/MacOS/Chess
PostBuild.ext_convertUTF.RelWithDebInfo: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/RelWithDebInfo/Chess.app/Contents/MacOS/Chess
PostBuild.ext_poly2tri.RelWithDebInfo: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/RelWithDebInfo/Chess.app/Contents/MacOS/Chess
PostBuild.ext_md5.RelWithDebInfo: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/RelWithDebInfo/Chess.app/Contents/MacOS/Chess
PostBuild.ext_unzip.RelWithDebInfo: /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/RelWithDebInfo/Chess.app/Contents/MacOS/Chess
/Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/RelWithDebInfo/Chess.app/Contents/MacOS/Chess:\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libcocos2d.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libexternal.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/Box2D/prebuilt/mac/libbox2d.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/chipmunk/prebuilt/mac/libchipmunk.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/freetype2/prebuilt/mac/libfreetype.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_recast.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libBulletDynamics.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libBulletCollision.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libBulletMultiThreaded.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libMiniCL.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/jpeg/prebuilt/mac/libjpeg.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/webp/prebuilt/mac/libwebp.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/websockets/prebuilt/mac/libwebsockets.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/openssl/prebuilt/mac/libssl.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/openssl/prebuilt/mac/libcrypto.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/uv/prebuilt/mac/libuv_a.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_tinyxml2.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_xxhash.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_xxtea.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_clipper.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_edtaa3func.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_convertUTF.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_poly2tri.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_md5.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/curl/prebuilt/mac/libcurl.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/png/prebuilt/mac/libpng.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glfw3/prebuilt/mac/libglfw3.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/zlib/prebuilt/mac/libz.a\
	/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_unzip.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glsl-optimizer/prebuilt/mac/libglcpp-library.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glsl-optimizer/prebuilt/mac/libglsl_optimizer.a\
	/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glsl-optimizer/prebuilt/mac/libmesa.a\
	/usr/lib/libiconv.dylib
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/bin/Chess/RelWithDebInfo/Chess.app/Contents/MacOS/Chess


PostBuild.ChessTests.RelWithDebInfo:
/Users/viragdoshi/dev/git/personal/Chess/bin/RelWithDebInfo/ChessTests:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/bin/RelWithDebInfo/ChessTests


PostBuild.cocos2d.RelWithDebInfo:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libcocos2d.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libcocos2d.a


PostBuild.ext_clipper.RelWithDebInfo:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_clipper.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_clipper.a


PostBuild.ext_convertUTF.RelWithDebInfo:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_convertUTF.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_convertUTF.a


PostBuild.ext_edtaa3func.RelWithDebInfo:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_edtaa3func.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_edtaa3func.a


PostBuild.ext_md5.RelWithDebInfo:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_md5.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_md5.a


PostBuild.ext_poly2tri.RelWithDebInfo:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_poly2tri.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_poly2tri.a


PostBuild.ext_recast.RelWithDebInfo:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_recast.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_recast.a


PostBuild.ext_tinyxml2.RelWithDebInfo:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_tinyxml2.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_tinyxml2.a


PostBuild.ext_unzip.RelWithDebInfo:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_unzip.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_unzip.a


PostBuild.ext_xxhash.RelWithDebInfo:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_xxhash.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_xxhash.a


PostBuild.ext_xxtea.RelWithDebInfo:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_xxtea.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_xxtea.a


PostBuild.external.RelWithDebInfo:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libexternal.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libexternal.a




# For each target create a dummy ruleso the target does not have to exist
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/Box2D/prebuilt/mac/libbox2d.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libBulletCollision.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libBulletDynamics.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libBulletMultiThreaded.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/bullet/prebuilt/mac/libMiniCL.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/chipmunk/prebuilt/mac/libchipmunk.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/curl/prebuilt/mac/libcurl.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/freetype2/prebuilt/mac/libfreetype.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glfw3/prebuilt/mac/libglfw3.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glsl-optimizer/prebuilt/mac/libglcpp-library.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glsl-optimizer/prebuilt/mac/libglsl_optimizer.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/glsl-optimizer/prebuilt/mac/libmesa.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/jpeg/prebuilt/mac/libjpeg.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/openssl/prebuilt/mac/libcrypto.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/openssl/prebuilt/mac/libssl.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/png/prebuilt/mac/libpng.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/uv/prebuilt/mac/libuv_a.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/webp/prebuilt/mac/libwebp.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/websockets/prebuilt/mac/libwebsockets.a:
/Users/viragdoshi/dev/git/personal/Chess/cocos2d/external/zlib/prebuilt/mac/libz.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libcocos2d.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_clipper.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_convertUTF.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_edtaa3func.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_md5.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_poly2tri.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_recast.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_tinyxml2.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_unzip.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_xxhash.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_xxtea.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libexternal.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libcocos2d.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_clipper.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_convertUTF.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_edtaa3func.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_md5.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_poly2tri.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_recast.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_tinyxml2.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_unzip.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_xxhash.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_xxtea.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libexternal.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libcocos2d.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_clipper.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_convertUTF.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_edtaa3func.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_md5.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_poly2tri.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_recast.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_tinyxml2.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_unzip.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_xxhash.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_xxtea.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libexternal.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libcocos2d.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_clipper.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_convertUTF.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_edtaa3func.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_md5.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_poly2tri.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_recast.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_tinyxml2.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_unzip.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_xxhash.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_xxtea.a:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libexternal.a:
/usr/lib/libiconv.dylib:
