# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.ext_md5.Debug:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_md5.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_md5.a


PostBuild.ext_md5.Release:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_md5.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_md5.a


PostBuild.ext_md5.MinSizeRel:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_md5.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_md5.a


PostBuild.ext_md5.RelWithDebInfo:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_md5.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_md5.a




# For each target create a dummy ruleso the target does not have to exist
