# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.ext_recast.Debug:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_recast.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Debug/libext_recast.a


PostBuild.ext_recast.Release:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_recast.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/Release/libext_recast.a


PostBuild.ext_recast.MinSizeRel:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_recast.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/MinSizeRel/libext_recast.a


PostBuild.ext_recast.RelWithDebInfo:
/Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_recast.a:
	/bin/rm -f /Users/viragdoshi/dev/git/personal/Chess/mac-build/lib/RelWithDebInfo/libext_recast.a




# For each target create a dummy ruleso the target does not have to exist
