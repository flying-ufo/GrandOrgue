/*
 * GrandOrgue - free pipe organ simulator
 *
 * Copyright 2006 Milan Digital Audio LLC
 * Copyright 2009-2019 GrandOrgue contributors (see AUTHORS)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef GORGUEARCHIVEMANAGER_H
#define GORGUEARCHIVEMANAGER_H

class GOrgueArchive;
class GOrgueOrganList;
class GOrgueSettings;
class GOrgueSettingDirectory;

#include <wx/string.h>

class GOrgueArchiveManager
{
private:
	GOrgueOrganList& m_OrganList;
	const GOrgueSettingDirectory& m_CacheDir;

	GOrgueArchive* OpenArchive(const wxString& path);
	bool ReadIndex(GOrgueArchive* archive, bool InstallOrgans = false);
	wxString InstallPackage(const wxString& path, const wxString& last_id);

public:
	GOrgueArchiveManager(GOrgueOrganList& OrganList, const GOrgueSettingDirectory& CacheDir);
	~GOrgueArchiveManager();

	GOrgueArchive* LoadArchive(const wxString& id);
	wxString InstallPackage(const wxString& path);
	bool RegisterPackage(const wxString& path);
	void RegisterPackageDirectory(const wxString& path);
};

#endif
