

Michael Howard  
Principal Cyber-Security Consultant  
Microsoft Corporation

June 2011

**This paper is derived from the book _[The Security Development Lifecycle](https://www.microsoft.com/mspress/books/8753.aspx)_, by Michael Howard and Steve Lipner, Microsoft Press, 2006.

Prohibiting the use of banned functions is a good way to remove a significant number of potential code vulnerabilities from C and C++ code. This practice is reflected in chapter 11 of _The Security Development Lifecycle_ book, as well as in the [SDL Process Guidance](https://msdn.microsoft.com/en-us/library/84aed186-1d75-4366-8e61-8d258746bopq.aspx) and [Simplified Implementation of the Microsoft SDL](http://go.microsoft.com/?linkid=9768052) whitepaper within the SDL Implementation phase.

When the C runtime library (CRT) was first created over three decades ago, the threats to computers were different; computers were not as interconnected as they are today, and attacks were not as prevalent. With this in mind, a subset of the C runtime library must be deprecated for new code and, over time, removed from earlier code. It's just too easy to get code wrong that uses these outdated functions and these types of errors lead to vulnerabilities. Even some of the classic replacement functions are prone to error too.

This list is the compiled library of known bad functions that should be removed to reduce vulnerabilities as part of your SDL practices. It is derived from experience with real-world security bugs and focuses primarily on functions that can lead to buffer overruns (_24 Deadly Sins of Software Development_; Howard, LeBlanc, and Viega 2009). Existing code must either replace the banned function with a more secure version or be re-architected so that the banned function is not used. For the functions marked as “recommended”, please consider this a strong recommendation and evaluate the function against your own security requirements, elevating them to “required” as necessary. In any case, none of the listed banned functions should be used in new code.

Notes:

*   The banned functions are either required or recommended based on:
    *   The assessed risk of the function with consideration of the overall difficulty of calling the function in a correct and “safe” manner.
    *   The availability of a safe replacement and the complexity of implementing a replacement.
*   Some of the function names might be a little different, depending on whether the function takes ASCII, Unicode, _T (ASCII or Unicode), or multibyte chars. Some function names might include _A_ or _W_ at the end of the name. For example, the StrSafe StringCbCatEx function is also available as StringCbCatExW (Unicode) and StringCbCatExA (ASCII).
*   Obviously, you cannot replace a banned function with another banned function. For example, replacing strcpy with strncpy is not valid because strncpy is banned, too.

**Table 1\. Banned string copy functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>StrSafe Replacement</th>

<th>Safe CRT Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">strcpy, strcpyA, strcpyW, wcscpy, _tcscpy, _mbscpy, StrCpy, StrCpyA, StrCpyW, lstrcpy, lstrcpyA, lstrcpyW, _tccpy, _mbccpy, _ftcscpy, strncpy, wcsncpy, _tcsncpy, _mbsncpy, _mbsnbcpy, StrCpyN, StrCpyNA, StrCpyNW, StrNCpy, strcpynA, StrNCpyA, StrNCpyW, lstrcpyn, lstrcpynA, lstrcpynW</td>

<td data-th="StrSafe Replacement">String*<span class="sup">1</span>Copy or String*CopyEx</td>

<td data-th="Safe CRT Replacement">strcpy_s</td>

</tr>

</tbody>

</table>

</div>

</div>

<span class="sup">1</span> For StrSafe, * should be replaced with Cch (character count) or Cb (byte count)

**Table 2\. Banned string concatenation functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>StrSafe Replacement</th>

<th>Safe CRT Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">strcat, strcatA, strcatW, wcscat, _tcscat, _mbscat, StrCat, StrCatA, StrCatW, lstrcat, lstrcatA, lstrcatW, StrCatBuff, StrCatBuffA, StrCatBuffW, StrCatChainW, _tccat, _mbccat, _ftcscat, strncat, wcsncat, _tcsncat, _mbsncat, _mbsnbcat, StrCatN, StrCatNA, StrCatNW, StrNCat, StrNCatA, StrNCatW, lstrncat, lstrcatnA, lstrcatnW, lstrcatn</td>

<td data-th="StrSafe Replacement">String*Cat or String*CatEx</td>

<td data-th="Safe CRT Replacement">strcat_s</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 3\. Banned sprintf functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>StrSafe Replacement</th>

<th>Safe CRT Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">sprintfW, sprintfA, wsprintf, wsprintfW, wsprintfA, sprintf, swprintf, _stprintf, wvsprintf, wvsprintfA, wvsprintfW, vsprintf, _vstprintf, vswprintf  
_Recommended_: wnsprintf, wnsprintfA, wnsprintfW, _snwprintf, snprintf, sntprintf _vsnprintf, vsnprintf, _vsnwprintf, _vsntprintf, wvnsprintf, wvnsprintfA, wvnsprintfW</td>

<td data-th="StrSafe Replacement">String*Printf or String*PrintfEx</td>

<td data-th="Safe CRT Replacement">sprintf_s</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 4\. Banned "n" sprintf functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>StrSafe Replacement</th>

<th>Safe CRT Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">_Recommended_: _snwprintf, _snprintf, _sntprintf, nsprintf</td>

<td data-th="StrSafe Replacement">String*Printf or String*PrintfEx</td>

<td data-th="Safe CRT Replacement">_snprintf_s or _snwprintf_s</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 5\. Banned variable argument sprintf functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>StrSafe Replacement</th>

<th>Safe CRT Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">wvsprintf, wvsprintfA, wvsprintfW, vsprintf, _vstprintf, vswprintf</td>

<td data-th="StrSafe Replacement">String*VPrintf or String*VPrintfEx</td>

<td data-th="Safe CRT Replacement">_vstprintf_s</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 6\. Banned variable argument "n" sprintf functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>StrSafe Replacement</th>

<th>Safe CRT Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">_Recommended_: _vsnprintf, _vsnwprintf, _vsntprintf, wvnsprintf, wvnsprintfA, wvnsprintfW</td>

<td data-th="StrSafe Replacement">String*VPrintf or String*VPrintfEx</td>

<td data-th="Safe CRT Replacement">vsntprintf_s</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 7\. Banned "n" string copy functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th class="style2">Banned Functions</th>

<th class="style2">StrSafe Replacement</th>

<th class="style2">Safe CRT Replacement</th>

</tr>

<tr>

<td class="style2" data-th="Banned Functions">strncpy, wcsncpy, _tcsncpy, _mbsncpy, _mbsnbcpy, StrCpyN, StrCpyNA, StrCpyNW, StrNCpy, strcpynA, StrNCpyA, StrNCpyW, lstrcpyn, lstrcpynA, lstrcpynW, _fstrncpy</td>

<td class="style2" data-th="StrSafe Replacement">String*CopyN or String*CopyNEx</td>

<td class="style2" data-th="Safe CRT Replacement">strncpy_s</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 8\. Banned "n" string concatenation functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>StrSafe Replacement</th>

<th>Safe CRT Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">strncat, wcsncat, _tcsncat, _mbsncat, _mbsnbcat, StrCatN, StrCatNA, StrCatNW, StrNCat, StrNCatA, StrNCatW, lstrncat, lstrcatnA, lstrcatnW, lstrcatn, _fstrncat</td>

<td data-th="StrSafe Replacement">String*CatN or String*CatNEx</td>

<td data-th="Safe CRT Replacement">strncat_s</td>

</tr>

</tbody>

</table>

</div>

</div>

Developers frequently replace functions like strcpy with the counted "n" version, such as strncpy. This practice is not recommended. In our experience, the "n" functions are also hard to secure (Howard 2004), so we have banned their use in new code.

**Table 9\. Banned string tokenizing functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>StrSafe Replacement</th>

<th>Safe CRT Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">_Recommended_: strtok, _tcstok, wcstok, _mbstok</td>

<td data-th="StrSafe Replacement">None</td>

<td data-th="Safe CRT Replacement">strtok_s</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 10\. Banned Makepath functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>StrSafe Replacement</th>

<th>Safe CRT Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">_Recommended_: makepath, _tmakepath, _makepath, _wmakepath</td>

<td data-th="StrSafe Replacement">None</td>

<td data-th="Safe CRT Replacement">_makepath_s</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 11\. Banned Splitpath functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>StrSafe Replacement</th>

<th>Safe CRT Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">_Recommended_: _splitpath, _tsplitpath, _wsplitpath</td>

<td data-th="StrSafe Replacement">None</td>

<td data-th="Safe CRT Replacement">_splitpath_s</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 12\. Banned scanf functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>StrSafe Replacement</th>

<th>Safe CRT Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">_Recommended_: scanf, wscanf, _tscanf, sscanf, swscanf, _stscanf</td>

<td data-th="StrSafe Replacement">None</td>

<td data-th="Safe CRT Replacement">sscanf_s</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 13\. Banned "n" scanf functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>StrSafe Replacement</th>

<th>Safe CRT Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">_Recommended_: snscanf, snwscanf, _sntscanf</td>

<td data-th="StrSafe Replacement">None</td>

<td data-th="Safe CRT Replacement">_snscanf_s</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 14\. Banned numeric conversion functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>StrSafe Replacement</th>

<th>Safe CRT Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">_Recommended_: _itoa, _itow, _i64toa, _i64tow, _ui64toa, _ui64tot, _ui64tow, _ultoa, _ultot, _ultow</td>

<td data-th="StrSafe Replacement">None</td>

<td data-th="Safe CRT Replacement">_itoa_s, _itow_s</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 15\. Banned gets functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>StrSafe Replacement</th>

<th>Safe CRT Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">gets, _getts, _gettws</td>

<td data-th="StrSafe Replacement">String*Gets</td>

<td data-th="Safe CRT Replacement">gets_s</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 16\. Banned IsBad* functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE">

<tbody>

<tr>

<th colspan="2">Banned Functions</th>

</tr>

<tr>

<td>IsBadWritePtr, IsBadHugeWritePtr, IsBadReadPtr, IsBadHugeReadPtr, IsBadCodePtr, IsBadStringPtr</td>

<td>These functions can mask errors, and there are no replacement functions. You should rewrite the code to avoid using these functions. If you need to avoid a crash, wrap your usage of the pointer with __try/__except. Doing this can easily hide bugs; you should do this only in areas where it is absolutely critical to avoid a crash (such as crash recovery code) and where you have a reasonable explanation for why the data you're looking at might be invalid. You should also not catch all exceptions, but only types that you know about. Catching all exceptions is just as bad as using IsBad*Ptr.

For IsBadWritePtr, filling the destination buffer using memset is a preferred way to validate that output buffers are valid and large enough to hold the amount of space that the caller claims they provided.

</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 17\. Banned OEM conversion functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>Windows Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">_Recommended_: CharToOem, CharToOemA, CharToOemW, OemToChar, OemToCharA, OemToCharW, CharToOemBuffA, CharToOemBuffW</td>

<td data-th="Windows Replacement">WideCharToMultiByte</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 18\. Banned stack dynamic memory allocation functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>Windows Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">_Recommended_: alloca, _alloca</td>

<td data-th="Windows Replacement">SafeAllocA</td>

</tr>

</tbody>

</table>

</div>

</div>

For critical applications, such as those accepting anonymous Internet connections, strlen must also be replaced:

**Table 19\. Banned string length functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>StrSafe Replacement</th>

<th>Safe CRT Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">_Recommended_: strlen, wcslen, _mbslen, _mbstrlen, StrLen, lstrlen</td>

<td data-th="StrSafe Replacement">String*Length</td>

<td data-th="Safe CRT Replacement">strnlen_s</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 20\. Banned memory copy functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

<th>StrSafe Replacement</th>

<th>Safe CRT Replacement</th>

</tr>

<tr>

<td data-th="Banned Functions">memcpy, RtlCopyMemory, CopyMemory, wmemcpy</td>

<td data-th="StrSafe Replacement">None</td>

<td data-th="Safe CRT Replacement">memcpy_s, wmemcpy_s</td>

</tr>

</tbody>

</table>

</div>

</div>

**Table 21\. Banned window messaging functions and replacements**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>Banned Functions</th>

</tr>

<tr>

<td data-th="Banned Functions">_Recommended_: ChangeWindowMessageFilter</td>

<td data-th="&nbsp;">This function is not recommended because it has process-wide scope. You can use ChangeWindowMessageFilterEx to control access for specific windows, but give careful consideration to any message filtering changes.</td>

</tr>

</tbody>

</table>

</div>

</div>

## Why the "n" Functions Are Banned

The classic C runtime, "n" functions (such as strncpy and strncat) are banned because they are so hard to call correctly. The authors have seen numerous errors calling these functions in an attempt to make code more secure. Note that we're not saying the replacements are perfect, but issues with the current "n" functions include non-null termination of overflowed buffers and no error returns on overflow.

The newer StrSafe and Safe CRT functions are more consistent on failure.

## Important Caveat

Simply replacing a banned function call with a better replacement does not guarantee that the code is secure. It's possible to misuse the replacement function, most commonly by getting the destination buffer size wrong.  
One way to make sure the function call is safe is to double check that the numberOfElements argument in a Safe CRT function call (such as strcpy_s) or the cchDest argument in a StrSafe function (such as StringCchCopy) is no larger than the destination buffer size. A good way to do this is to use a _countof(buffer) call. Examples are shown later in this document.

## Choosing StrSafe vs. Safe CRT

There is an overlap between these two sets of replacement C runtime functions. Which you choose depends on your specific situation; the following table should help you make the decision. In some cases, you might have little choice but to use one over the other; for example, if your code calls itoa, there is no replacement in StrSafe, but there is in Safe CRT. You would need to either code around the itoa call or use Safe CRT.

**Table 22\.**

<div class="tablediv">

<div class="contentTableWrapper">

<table class="dtTABLE" responsive="true">

<tbody>

<tr>

<th>StrSafe</th>

<th>Safe CRT</th>

</tr>

<tr>

<td data-th="&nbsp;">**Distribution Method**</td>

<td data-th="StrSafe">Web (_[http://msdn.microsoft.com](https://msdn.microsoft.com/)_)</td>

<td data-th="Safe CRT">Microsoft Visual Studio 2005 or later</td>

</tr>

<tr>

<td data-th="&nbsp;">**# Headers**</td>

<td data-th="StrSafe">One (StrSafe.h)</td>

<td data-th="Safe CRT">Numerous (various C runtime headers)</td>

</tr>

<tr>

<td data-th="&nbsp;">**Library Version Available**</td>

<td data-th="StrSafe">Yes</td>

<td data-th="Safe CRT">Yes</td>

</tr>

<tr>

<td data-th="&nbsp;">**Inline Version Available**</td>

<td data-th="StrSafe">Yes</td>

<td data-th="Safe CRT">No</td>

</tr>

<tr>

<td data-th="&nbsp;">**Industry Standard**</td>

<td data-th="StrSafe">No</td>

<td data-th="Safe CRT">Not Yet (Secure C Lib Functions)</td>

</tr>

<tr>

<td data-th="&nbsp;">**Kernel Mode**</td>

<td data-th="StrSafe">Yes</td>

<td data-th="Safe CRT">No</td>

</tr>

<tr>

<td data-th="&nbsp;">**Return Type**</td>

<td data-th="StrSafe">HRESULT (user) or NTSTATUS (kernel)</td>

<td data-th="Safe CRT">Varies by function (errno_t)</td>

</tr>

<tr>

<td data-th="&nbsp;">**Requires Code Changes**</td>

<td data-th="StrSafe">Yes</td>

<td data-th="Safe CRT">Yes</td>

</tr>

<tr>

<td data-th="&nbsp;">**Main Focus**</td>

<td data-th="StrSafe">Buffer overrun issues</td>

<td data-th="Safe CRT">Various, including buffer overruns</td>

</tr>

</tbody>

</table>

</div>

</div>

## Using StrSafe

To use StrSafe in your C or C++ code, simply add the following header:

<div id="code-snippet-1" class="codeSnippetContainer" xmlns="">

<div class="codeSnippetContainerCodeContainer">

<div class="codeSnippetToolBar">

<div class="codeSnippetToolBarText">[Copy](javascript:if (window.epx.codeSnippet)window.epx.codeSnippet.copyCode('CodeSnippetContainerCode_bb009b70-2244-47b7-b97f-a0806b6e3de7'); "Copy to clipboard.")</div>

</div>

<div id="CodeSnippetContainerCode_bb009b70-2244-47b7-b97f-a0806b6e3de7" class="codeSnippetContainerCode" dir="ltr">

<div style="color:Black;">

<pre>#include "strsafe.h"
</pre>

</div>

</div>

</div>

</div>

This will make the functions inline. If you want to use the library version, Strsafe.lib, add the following to your code:

<div id="code-snippet-2" class="codeSnippetContainer" xmlns="">

<div class="codeSnippetContainerCodeContainer">

<div class="codeSnippetToolBar">

<div class="codeSnippetToolBarText">[Copy](javascript:if (window.epx.codeSnippet)window.epx.codeSnippet.copyCode('CodeSnippetContainerCode_1b566965-56be-435f-bc5a-5b97c19c1b5e'); "Copy to clipboard.")</div>

</div>

<div id="CodeSnippetContainerCode_1b566965-56be-435f-bc5a-5b97c19c1b5e" class="codeSnippetContainerCode" dir="ltr">

<div style="color:Black;">

<pre>#define STRSAFE_LIB
#include "strsafe.h"
</pre>

</div>

</div>

</div>

</div>

Note that all the StrSafe functions include Rtl versions for kernel use.

### StrSafe Example

The following code

<div id="code-snippet-3" class="codeSnippetContainer" xmlns="">

<div class="codeSnippetContainerCodeContainer">

<div class="codeSnippetToolBar">

<div class="codeSnippetToolBarText">[Copy](javascript:if (window.epx.codeSnippet)window.epx.codeSnippet.copyCode('CodeSnippetContainerCode_0795b6f5-a44c-406c-bfa2-4e5ea24a4119'); "Copy to clipboard.")</div>

</div>

<div id="CodeSnippetContainerCode_0795b6f5-a44c-406c-bfa2-4e5ea24a4119" class="codeSnippetContainerCode" dir="ltr">

<div style="color:Black;">

<pre>void Function(char *s1, char *s2) {
    char temp[32];
    strcpy(temp,s1);
    strcat(temp,s2);
}
</pre>

</div>

</div>

</div>

</div>

when converted to StrSafe might look like this:

<div id="code-snippet-4" class="codeSnippetContainer" xmlns="">

<div class="codeSnippetContainerCodeContainer">

<div class="codeSnippetToolBar">

<div class="codeSnippetToolBarText">[Copy](javascript:if (window.epx.codeSnippet)window.epx.codeSnippet.copyCode('CodeSnippetContainerCode_f5a621ee-f5d6-497a-a3c9-3322162eeb9a'); "Copy to clipboard.")</div>

</div>

<div id="CodeSnippetContainerCode_f5a621ee-f5d6-497a-a3c9-3322162eeb9a" class="codeSnippetContainerCode" dir="ltr">

<div style="color:Black;">

<pre>HRESULT Function(char *s1, char *s2) {
    char temp[32];
    HRESULT hr = StringCchCopy(temp,_countof(temp), s1);
    if (FAILED(hr)) return hr;
    return StringCchCat(temp,_countof(temp), s2);
}
</pre>

</div>

</div>

</div>

</div>

## Using Safe CRT

The Safe CRT is included starting with Visual Studio 2005\. When you compile code using this compiler, it will automatically warn you of the deprecated functions in the code. Also, in some cases, the compiler will change some function calls to safe function calls if the destination buffer size is known at compile time and CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES is #defined in the code.

For example, the following code

<div id="code-snippet-5" class="codeSnippetContainer" xmlns="">

<div class="codeSnippetContainerCodeContainer">

<div class="codeSnippetToolBar">

<div class="codeSnippetToolBarText">[Copy](javascript:if (window.epx.codeSnippet)window.epx.codeSnippet.copyCode('CodeSnippetContainerCode_8a3cd7fa-9ada-4cf7-9f09-542e4b986fc9'); "Copy to clipboard.")</div>

</div>

<div id="CodeSnippetContainerCode_8a3cd7fa-9ada-4cf7-9f09-542e4b986fc9" class="codeSnippetContainerCode" dir="ltr">

<div style="color:Black;">

<pre>int main(int argc, char* argv[]) {
    char t[10];
       ...
    if (2==argc) 
        strcpy(t,argv[1]);

       ...
    return 0;

}
</pre>

</div>

</div>

</div>

</div>

is changed by the compiler to this:

<div id="code-snippet-6" class="codeSnippetContainer" xmlns="">

<div class="codeSnippetContainerCodeContainer">

<div class="codeSnippetToolBar">

<div class="codeSnippetToolBarText">[Copy](javascript:if (window.epx.codeSnippet)window.epx.codeSnippet.copyCode('CodeSnippetContainerCode_3cfadf29-e0e6-40d4-a65f-a79fdb545f46'); "Copy to clipboard.")</div>

</div>

<div id="CodeSnippetContainerCode_3cfadf29-e0e6-40d4-a65f-a79fdb545f46" class="codeSnippetContainerCode" dir="ltr">

<div style="color:Black;">

<pre>int main(int argc, char* argv[]) {
    char t[10];
   ...
   if (2==argc) 
       strcpy_s(t,_countof(t),argv[1]);

   ...
   return 0;
}
</pre>

</div>

</div>

</div>

</div>

### Safe CRT Example

The following code

<div id="code-snippet-7" class="codeSnippetContainer" xmlns="">

<div class="codeSnippetContainerCodeContainer">

<div class="codeSnippetToolBar">

<div class="codeSnippetToolBarText">[Copy](javascript:if (window.epx.codeSnippet)window.epx.codeSnippet.copyCode('CodeSnippetContainerCode_28a1e6c4-07b9-435f-89e5-9fd76c50fee8'); "Copy to clipboard.")</div>

</div>

<div id="CodeSnippetContainerCode_28a1e6c4-07b9-435f-89e5-9fd76c50fee8" class="codeSnippetContainerCode" dir="ltr">

<div style="color:Black;">

<pre>void Function(char *s1, char *s2) {
    char temp[32];
    strcpy(temp,s1);
    strcat(temp,s2);
}
</pre>

</div>

</div>

</div>

</div>

when converted to the Safe CRT might look like this:

<div id="code-snippet-8" class="codeSnippetContainer" xmlns="">

<div class="codeSnippetContainerCodeContainer">

<div class="codeSnippetToolBar">

<div class="codeSnippetToolBarText">[Copy](javascript:if (window.epx.codeSnippet)window.epx.codeSnippet.copyCode('CodeSnippetContainerCode_8463ec7d-d3bb-4956-92c9-98216a67ca42'); "Copy to clipboard.")</div>

</div>

<div id="CodeSnippetContainerCode_8463ec7d-d3bb-4956-92c9-98216a67ca42" class="codeSnippetContainerCode" dir="ltr">

<div style="color:Black;">

<pre>errno_t Function(char *s1, char *s2) {
    char temp[32];
    errno_t err = strcpy_s(temp,_countof(temp), s1);
    if (!err) return err;
    return strcat_s(temp,_countof(temp), s2);
}
</pre>

</div>

</div>

</div>

</div>

## Other Replacements

If you are using C++, you should seriously consider using the std::string template class rather than manipulating buffers directly.

Many *nix variants, including OpenBSD and some Linux operating systems, include support for string copy replacements strlcpy and strlcat (Miller and de Raadt 1999).

## Tools Support

The Visual Studio 2005 (and later) compiler has built-in deprecations for these functions; all C4996 compiler warnings should be investigated to make sure that the function in question is not on the preceding banned list. Also, look out for code that disables this warning, such as _#pragma warning(disable:4996)_.

## ROI and Cost Impact

As stated earlier, removing banned functions is one way to reduce potential security bugs with very little engineering effort, as can be seen at the start of this document. Some Microsoft security bulletins would not have been necessary if banned functions had not been used, so the potential cost savings for an organization can be significant.

## Metrics and Goals

The metric to track is the number of banned functions in former code and in new code. The quantity should be zero for new code and should follow a glide path down over time for former code.

## References

**(Howard, LeBlanc, and Viega 2009)**

Howard, Michael, David LeBlanc, and John Viega. _24 Deadly Sins of Software Development_. New York, NY: McGraw-Hill, 2009\. Chapter 5, "Buffer Overruns."

**(Howard 2004)**

Howard, Michael. "Buffer Overflow in Apache 1.3.xx fixed on Bugtraq—the evils of strncpy and strncat," [http://blogs.msdn.com/michael_howard/archive/2004/10/29/249713.aspx](http://blogs.msdn.com/michael_howard/archive/2004/10/29/249713.aspx), October 2004.

**(Miller and de Raadt 1999)**

Miller, Todd C., and Theo de Raadt. USENIX Annual Technical Conference, "strlcpy and strlcat – Consistent, Safe String Copy and Concatenation," [http://www.usenix.org/events/usenix99/full_papers/millert/millert_html/index.html](http://www.usenix.org/events/usenix99/full_papers/millert/millert_html/index.html), June 1999.
