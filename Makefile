INC = -I/utils -IClasses -Icocos2d/cocos/audio/include -Icocos2d -Icocos2d/cocos -Icocos2d/extensions -Icocos2d/cocos/platform -Icocos2d/cocos/editor-support -Icocos2d/cocos/base -Icocos2d/cocos/platform/mac -Icocos2d/external/recast/.. -Icocos2d/external/tinyxml2/. -Icocos2d/external/xxhash/. -Icocos2d/external/xxtea/. -Icocos2d/external/clipper/. -Icocos2d/external/edtaa3func/. -Icocos2d/external/ConvertUTF/. -Icocos2d/external/poly2tri/.. -Icocos2d/external/md5/.. -Icocos2d/external/unzip/. -Icocos2d/external/Box2D/include -Icocos2d/external/chipmunk/include -Icocos2d/external/freetype2/include/mac/freetype2 -Icocos2d/external/bullet/include -Icocos2d/external/bullet/include/bullet -Icocos2d/external/jpeg/include/mac -Icocos2d/external/openssl/include/mac -Icocos2d/external/uv/include -Icocos2d/external/webp/include/mac -Icocos2d/external/websockets/include/mac -Icocos2d/external/curl/include/mac -Icocos2d/external/png/include/mac -Icocos2d/external/glfw3/include/mac -Icocos2d/external/zlib/include -Icocos2d/external/glsl-optimizer/include
CFLAGS = -std=c++11 -DAPP_UTILS
OBJ = obj

tests: 
	g++ $(CFLAGS) $(INC) -c Classes/Bitboard.cpp -o $(OBJ)/Bitboard.o
	g++ $(CFLAGS) $(INC) -c utils/BitboardPrint.cpp -o $(OBJ)/BitboardPrint.o
	g++ $(OBJ)/Bitboard.o $(OBJ)/BitboardPrint.o -o $(OBJ)/test
