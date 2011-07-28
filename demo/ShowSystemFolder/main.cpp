#include <iostream>

int main (int argc, char * const argv[]) {
    // insert code here...
    system("defaults write com.apple.finder AppleShowAllFiles -bool true");
	system("KillAll Finder");
    return 0;
}
