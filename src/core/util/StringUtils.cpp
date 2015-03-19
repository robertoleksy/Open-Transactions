/************************************************************
 *
 *  StringUtils.cpp
 *
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1

 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.

 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.9 (Darwin)

 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/

#include <opentxs/core/util/Common.hpp>
#include <opentxs/core/util/StringUtils.hpp>
#include <opentxs/core/util/Assert.hpp>

#ifdef ANDROID
#include <time64.h>
#endif

namespace opentxs
{

// If 10 is passed in, then 11 will be allocated,
// then the data is copied, and then the result[10] (11th element)
// is set to 0. This way the original 10-length string is untouched.
//
char* str_dup2(const char* str, uint32_t length) // length doesn't/shouldn't
                                                 // include the byte for the
                                                 // terminating 0.
{
    char* str_new = new char[length + 1]; // CREATE EXTRA BYTE OF SPACE FOR \0
                                          // (NOT PART OF LENGTH)
    OT_ASSERT(nullptr != str_new);

#ifdef _WIN32
    strncpy_s(str_new, length + 1, str, length);
#else
    strncpy(str_new, str, length);
#endif

    // INITIALIZE EXTRA BYTE OF SPACE
    //
    // If length is 10, then buffer is created with 11 elements,
    // indexed from 0 (first element) through 10 (11th element).
    //
    // Therefore str_new[length==10] is the 11th element, which was
    // the extra one created on our buffer, to store the \0 null terminator.
    //
    // This way I know I'm never cutting off data that was in the string itself.
    // Rather, I am only setting to 0 an EXTRA byte that I created myself, AFTER
    // the string's length itself.
    //
    str_new[length] = '\0';

    return str_new;
}

} // namespace opentxs

std::string formatTimestamp(time64_t tt)
{
    struct tm tm;
    time_t t = tt;
    char buf[255];
#if defined(_WIN32)
	gmtime_s(&tm, &t);
	strftime(buf, sizeof(buf), "%FT%T", &tm);
#else
	strftime(buf, sizeof(buf), "%FT%T", gmtime_r(&t, &tm));
#endif
    return std::string(buf);
}

std::string getTimestamp()
{
    return formatTimestamp(time(NULL));
}

#ifdef _MSC_VER
char * strptime(const char *s, const char *format, struct tm *tm);
#endif

time64_t parseTimestamp(std::string extendedTimeString)
{
    struct tm tm;
    if (!strptime(extendedTimeString.c_str(), "%Y-%m-%dT%H:%M:%S", &tm)) {
        return 0;
    }

#ifdef ANDROID
    time64_t t = timegm64(&tm);
#elif defined(_WIN32)
	time_t time = mktime(&tm);
	tm = *gmtime(&time);
	time_t t = mktime(&tm);
#else
    time_t t = timegm(&tm);
#endif
    if (t == -1) return 0;
    return t;
}

//strptime() from
//http://stackoverflow.com/questions/667250/strptime-in-windows

#ifdef _MSC_VER
const char * strp_weekdays[] =
{ "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
const char * strp_monthnames[] =
{ "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
bool strp_atoi(const char * & s, int & result, int low, int high, int offset)
{
	bool worked = false;
	char * end;
	unsigned long num = strtoul(s, &end, 10);
	if (num >= (unsigned long)low && num <= (unsigned long)high)
	{
		result = (int)(num + offset);
		s = end;
		worked = true;
	}
	return worked;
}
char * strptime(const char *s, const char *format, struct tm *tm)
{
	bool working = true;
	while (working && *format && *s)
	{
		switch (*format)
		{
		case '%':
		{
					++format;
					switch (*format)
					{
					case 'a':
					case 'A': // weekday name
						tm->tm_wday = -1;
						working = false;
						for (size_t i = 0; i < 7; ++i)
						{
							size_t len = strlen(strp_weekdays[i]);
							if (!strnicmp(strp_weekdays[i], s, len))
							{
								tm->tm_wday = i;
								s += len;
								working = true;
								break;
							}
							else if (!strnicmp(strp_weekdays[i], s, 3))
							{
								tm->tm_wday = i;
								s += 3;
								working = true;
								break;
							}
						}
						break;
					case 'b':
					case 'B':
					case 'h': // month name
						tm->tm_mon = -1;
						working = false;
						for (size_t i = 0; i < 12; ++i)
						{
							size_t len = strlen(strp_monthnames[i]);
							if (!strnicmp(strp_monthnames[i], s, len))
							{
								tm->tm_mon = i;
								s += len;
								working = true;
								break;
							}
							else if (!strnicmp(strp_monthnames[i], s, 3))
							{
								tm->tm_mon = i;
								s += 3;
								working = true;
								break;
							}
						}
						break;
					case 'd':
					case 'e': // day of month number
						working = strp_atoi(s, tm->tm_mday, 1, 31, 0);
						break;
					case 'D': // %m/%d/%y
					{
								  const char * s_save = s;
								  working = strp_atoi(s, tm->tm_mon, 1, 12, -1);
								  if (working && *s == '/')
								  {
									  ++s;
									  working = strp_atoi(s, tm->tm_mday, 1, 31, 0);
									  if (working && *s == '/')
									  {
										  ++s;
										  working = strp_atoi(s, tm->tm_year, 0, 99, 0);
										  if (working && tm->tm_year < 69)
											  tm->tm_year += 100;
									  }
								  }
								  if (!working)
									  s = s_save;
					}
						break;
					case 'H': // hour
						working = strp_atoi(s, tm->tm_hour, 0, 23, 0);
						break;
					case 'I': // hour 12-hour clock
						working = strp_atoi(s, tm->tm_hour, 1, 12, 0);
						break;
					case 'j': // day number of year
						working = strp_atoi(s, tm->tm_yday, 1, 366, -1);
						break;
					case 'm': // month number
						working = strp_atoi(s, tm->tm_mon, 1, 12, -1);
						break;
					case 'M': // minute
						working = strp_atoi(s, tm->tm_min, 0, 59, 0);
						break;
					case 'n': // arbitrary whitespace
					case 't':
						while (isspace((int)*s))
							++s;
						break;
					case 'p': // am / pm
						if (!strnicmp(s, "am", 2))
						{ // the hour will be 1 -> 12 maps to 12 am, 1 am .. 11 am, 12 noon 12 pm .. 11 pm
							if (tm->tm_hour == 12) // 12 am == 00 hours
								tm->tm_hour = 0;
						}
						else if (!strnicmp(s, "pm", 2))
						{
							if (tm->tm_hour < 12) // 12 pm == 12 hours
								tm->tm_hour += 12; // 1 pm -> 13 hours, 11 pm -> 23 hours
						}
						else
							working = false;
						break;
					case 'r': // 12 hour clock %I:%M:%S %p
					{
								  const char * s_save = s;
								  working = strp_atoi(s, tm->tm_hour, 1, 12, 0);
								  if (working && *s == ':')
								  {
									  ++s;
									  working = strp_atoi(s, tm->tm_min, 0, 59, 0);
									  if (working && *s == ':')
									  {
										  ++s;
										  working = strp_atoi(s, tm->tm_sec, 0, 60, 0);
										  if (working && isspace((int)*s))
										  {
											  ++s;
											  while (isspace((int)*s))
												  ++s;
											  if (!strnicmp(s, "am", 2))
											  { // the hour will be 1 -> 12 maps to 12 am, 1 am .. 11 am, 12 noon 12 pm .. 11 pm
												  if (tm->tm_hour == 12) // 12 am == 00 hours
													  tm->tm_hour = 0;
											  }
											  else if (!strnicmp(s, "pm", 2))
											  {
												  if (tm->tm_hour < 12) // 12 pm == 12 hours
													  tm->tm_hour += 12; // 1 pm -> 13 hours, 11 pm -> 23 hours
											  }
											  else
												  working = false;
										  }
									  }
								  }
								  if (!working)
									  s = s_save;
					}
						break;
					case 'R': // %H:%M
					{
								  const char * s_save = s;
								  working = strp_atoi(s, tm->tm_hour, 0, 23, 0);
								  if (working && *s == ':')
								  {
									  ++s;
									  working = strp_atoi(s, tm->tm_min, 0, 59, 0);
								  }
								  if (!working)
									  s = s_save;
					}
						break;
					case 'S': // seconds
						working = strp_atoi(s, tm->tm_sec, 0, 60, 0);
						break;
					case 'T': // %H:%M:%S
					{
								  const char * s_save = s;
								  working = strp_atoi(s, tm->tm_hour, 0, 23, 0);
								  if (working && *s == ':')
								  {
									  ++s;
									  working = strp_atoi(s, tm->tm_min, 0, 59, 0);
									  if (working && *s == ':')
									  {
										  ++s;
										  working = strp_atoi(s, tm->tm_sec, 0, 60, 0);
									  }
								  }
								  if (!working)
									  s = s_save;
					}
						break;
					case 'w': // weekday number 0->6 sunday->saturday
						working = strp_atoi(s, tm->tm_wday, 0, 6, 0);
						break;
					case 'Y': // year
						working = strp_atoi(s, tm->tm_year, 1900, 65535, -1900);
						break;
					case 'y': // 2-digit year
						working = strp_atoi(s, tm->tm_year, 0, 99, 0);
						if (working && tm->tm_year < 69)
							tm->tm_year += 100;
						break;
					case '%': // escaped
						if (*s != '%')
							working = false;
						++s;
						break;
					default:
						working = false;
					}
		}
			break;
		case ' ':
		case '\t':
		case '\r':
		case '\n':
		case '\f':
		case '\v':
			// zero or more whitespaces:
			while (isspace((int)*s))
				++s;
			break;
		default:
			// match character
			if (*s != *format)
				working = false;
			else
				++s;
			break;
		}
		++format;
	}
	return (working ? (char *)s : 0);
}
#endif // _MSC_VER