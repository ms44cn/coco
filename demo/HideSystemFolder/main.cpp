#include <iostream>

int main (int argc, char * const argv[]) {
    // insert code here...
    system("defaults write com.apple.finder AppleShowAllFiles -bool false");
	system("KillAll Finder");
    return 0;
}
