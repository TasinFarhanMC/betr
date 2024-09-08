pkgname=betr
pkgver="c++11"
pkgrel=1
pkgdesc="A C++ Library With Better Standards"
arch=('any')
url="https://github.com/TasinFarhanMC/betr"
license=('MIT')
depends=('cmake' 'gcc')
source=("https://github.com/TasinFarhanMC/betr/archive/refs/heads/c++11.zip")
sha256sums=('SKIP')  # Replace with the actual checksum of the source tarball

prepare() {
  cd "$srcdir/${pkgname}-${pkgver}"
}

build() {
  cmake -S .. -B build -DCMAKE_INSTALL_PREFIX=$(pwd)/test_install
}

package() {
  cmake --install .
  cp -r $(pwd)/test_install/* $pkgdir/
}
