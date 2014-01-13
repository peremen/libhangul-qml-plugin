#
# spec file for package libhangul
#
# Copyright (c) 2012 SUSE LINUX Products GmbH, Nuernberg, Germany.
#
# All modifications and additions to the file contributed by third parties
# remain the property of their copyright owners, unless otherwise agreed
# upon. The license for this file, and modifications and additions to the
# file, is the same license as for the pristine package itself (unless the
# license for the pristine package is not an Open Source License, in which
# case the license is the MIT License). An "Open Source License" is a
# license that conforms to the Open Source Definition (Version 1.9)
# published by the Open Source Initiative.

# Please submit bugfixes or comments via http://bugs.opensuse.org/
#


%define libname libhangul1

Name:           libhangul
Version:        0.1.0
Release:        0
Summary:        Hangul input library used by scim-hangul and ibus-hangul
License:        LGPL-2.1+
Group:          System/I18n/Korean
Url:            http://code.google.com/p/libhangul/
Source0:        http://libhangul.googlecode.com/files/%{name}-%{version}.tar.gz
BuildRequires:  libtool
BuildRequires:  pkgconfig
BuildRoot:      %{_tmppath}/%{name}-%{version}-build

%description
Hangul input library used by scim-hangul and ibus-hangul

%package -n %{libname}
Summary:        Hangul input library used by scim-hangul and ibus-hangul
Group:          System/I18n/Korean

%description -n %{libname}
Hangul input library used by scim-hangul and ibus-hangul

%package devel
Summary:        Include Files and Libraries mandatory for Development
Group:          System/I18n/Korean
Requires:       %{libname} = %{version}
Requires:       glibc-devel

%description devel
This package contains all necessary include files and libraries needed
to develop applications that require these.

%prep
%setup -q

%build
#autoreconf --force --install --verbose
export CFLAGS="%{optflags}"
export CXXFLAGS="%{optflags}"
%configure --disable-static --with-pic
make %{?_smp_mflags}

%install
%makeinstall
rm -f %{buildroot}%{_libdir}/*.la

%post -n %{libname} -p /sbin/ldconfig

%postun -n %{libname} -p /sbin/ldconfig

%files -n %{libname}
%defattr(-, root, root)
%doc AUTHORS COPYING NEWS README ChangeLog
%{_libdir}/lib*.so.*
%dir %{_datadir}/libhangul/
%dir %{_datadir}/libhangul/hanja/
%{_datadir}/libhangul/hanja/hanja.txt
%{_bindir}/hangul
%{_datadir}/locale/ko/LC_MESSAGES/libhangul.mo

%files devel
%defattr(-, root, root)
%dir %{_includedir}/hangul-1.0/
%{_includedir}/hangul-1.0/*
%{_libdir}/lib*.so
%{_libdir}/pkgconfig/libhangul.pc

%changelog
