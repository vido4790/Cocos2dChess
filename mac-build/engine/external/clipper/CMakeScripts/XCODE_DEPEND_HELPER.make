# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.ext_clipper.Debug:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_clipper.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_clipper.a


PostBuild.ext_clipper.Release:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_clipper.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_clipper.a


PostBuild.ext_clipper.MinSizeRel:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_clipper.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_clipper.a


PostBuild.ext_clipper.RelWithDebInfo:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_clipper.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_clipper.a




# For each target create a dummy ruleso the target does not have to exist
