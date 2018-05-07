<div dir="rtl">

<div dir="rtl">
  <a href="#qt-project">راه‌اندازی پروژه QT</a>
  <br />
  <a href="#interstitial">پیاده‌سازی تبلیغات ویدئویی (Interstitial/Rewarded Video) و بنری تمام صفحه (Interstitial Banner) در پروژه Qt</a>
  <br />
  <a href="#native-banner-implementaion">پیاده‌سازی تبلیغات بنری هم‌نما (Native Banner) در پروژه Qt</a>
  <br />
  <a href="#native-video-implementation">پیاده‌سازی تبلیغات ویدیویی هم‌نما (Native Video) در پروژه Qt</a>
  <br />
  <a href="#standard-banner">پیاده‌سازی تبلیغات بنری استاندارد در پروژه Qt</a>
  <br />
  <a href="https://github.com/tapselladnet/TapsellSDK_v3_Qt">پروژه نمونه</a>
  <br />
</div>

<div dir="rtl" id="qt-project">
<h1>راه‌اندازی پروژه QT</h1>
<h3>گام ۱: دریافت پلاگین تپسل برای Qt</h3>
ابتدا فایل پلاگین تپسل برای Qt را از آدرس زیر را دانلود کنید.
<p style="text-align: center;"><a href="https://storage.backtory.com/tapsell-server/sdk/tapsell-qt.zip"><button>دانلود پلاگین</button></a></p>

<h3>گام ۲: راه اندازی پلتفرم های android و iOS</h3>
حال با توجه به پلتفرم مورد نظر شما ، ادامه‌ی مراحل را در لینک زیر ادامه دهید و سپس به این صفحه بازگشته و به گام ۳ بروید:
<p style="text-align: center;"><a href="#android-project"><button>پلتفرم Android</button></a></p>
<p style="text-align: center;"><a href="#ios-project"><button>پلتفرم iOS</button></a></p>

<h3>گام ۳:‌ اضافه کردن پلاگین تپسل به پروژه Qt</h3>
پلاگین دریافت شده در گام یک را از حالت فشرده خارج کرده و آن را در محل پروژه خود قرار دهید. سپس کد های زیر را به فایل pro. پروژه خود  اضافه کنید:
<pre class="hljs" style="display: block; overflow-x: auto; padding: 0.5em; background: #f0f0f0; color: #444444;" dir="ltr">QT += gui gui-private

ios: SOURCES += \
    TapsellSDKAndHelpers/tapsellIos<span class="hljs-selector-class" style="color: #880000;">.cpp</span> \

ios: HEADERS += \
    TapsellSDKAndHelpers/tapsellIos<span class="hljs-selector-class" style="color: #880000;">.h</span>

ios: OBJECTIVE_SOURCES += \
    TapsellSDKAndHelpers/TSTapsell<span class="hljs-selector-class" style="color: #880000;">.mm</span>

ios: OBJECTIVE_HEADERS += \
    TapsellSDKAndHelpers/TSTapsell<span class="hljs-selector-class" style="color: #880000;">.h</span>

QMAKE_INFO_PLIST = TapsellSDKAndHelpers/info<span class="hljs-selector-class" style="color: #880000;">.plist</span>

android: QT += androidextras

android: SOURCES += \
    TapsellSDKAndHelpers/tapsellAndroid<span class="hljs-selector-class" style="color: #880000;">.cpp</span>

android: HEADERS += \
    TapsellSDKAndHelpers/tapsellAndroid<span class="hljs-selector-class" style="color: #880000;">.h</span>

android: DISTFILES += \
    android/AndroidManifest<span class="hljs-selector-class" style="color: #880000;">.xml</span> \
    android/gradle/wrapper/gradle-wrapper<span class="hljs-selector-class" style="color: #880000;">.jar</span> \
    android/gradlew \
    android/res/values/libs<span class="hljs-selector-class" style="color: #880000;">.xml</span> \
    android/build<span class="hljs-selector-class" style="color: #880000;">.gradle</span> \
    android/gradle/wrapper/gradle-wrapper<span class="hljs-selector-class" style="color: #880000;">.properties</span> \
    android/gradlew<span class="hljs-selector-class" style="color: #880000;">.bat</span> \
    android/src/ir/tapsell/sdk/Tapsell<span class="hljs-selector-class" style="color: #880000;">.java</span>

ANDROID_PACKAGE_SOURCE_DIR = $<span class="hljs-variable" style="color: #bc6060;">$PWD</span>/android</pre>
<h3>نمونه پیاده‌سازی</h3>
یک نمونه پیاده‌سازی پلاگین Qt تپسل در repository زیر آمده است.
<p style="text-align: center;"><a href="https://github.com/hermamitr/TapsellSDK_v3_Qt"><button>مشاهده پروژه نمونه</button></a></p>
</div>

<div dir="rtl" id="android-project">
  <h1>راه‌اندازی پلاگین تپسل در پلتفرم android در Qt</h1>

  <h3>گام ۱: ساختن پوشه android در پروژه Qt</h3>
اگر قبلا پوشه android در مسیر پروژه Qt خود نساخته اید ، این مراحل را طی کنید و پوشه android را بسازید :

وارد قسمت تنظیمات پروژه شوید :
<br/><img class=" wp-image-2577 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2018/01/Screenshot-from-2018-01-06-18-11-45.png" alt="" width="53" height="237" /><br />

در قسمت Build Android APK گزینه Create Templates را انتخاب کنید :
<br />
<img class="aligncenter wp-image-2578" src="https://answers.tapsell.ir/wp-content/uploads/2018/01/Screenshot-from-2018-01-06-18-13-27.png" alt="" width="608" height="491" /><br />

سپس گزینه Finish را انتخاب کنید ، با این کار پوشه android باید ساخته شود :
<br/>
<img class="aligncenter wp-image-2579" src="https://answers.tapsell.ir/wp-content/uploads/2018/01/Screenshot-from-2018-01-06-18-14-15.png" alt="" width="366" height="281" /><br/>
<h3>گام ۲ : اضافه کردن tapsell.jar به پروژه اندروید</h3>
فایل tapsell.jar موجود در پلاگین تپسل (دانلود شده در مراحل قبلی) ، را در پوشه <code>android/libs</code> از محل پروژه خود ، کپی کنید.
<h3>گام ۳: اضافه کردن فایل Tapsell.java به پروژه اندروید</h3>
فایل Tapsell.java موجود در پلاگین تپسل را در پوشه<code>android/src/ir/tapsell/sdk</code> از محل پروژه خود ، کپی کنید.
<h3>گام ۴: اضافه کردن TapsellAdActivity به AndroidManifest.xml</h3>
فایل AndroidManifest.xml پروژه اندروید (واقع در پوشه<code>android</code> از محل پروژه) را باز کرده و تکه کد زیر را درون تگ <code>&lt;application&gt;...&lt;/application&gt;</code> قرار دهید :
<pre style="color: #000000; background: #ffffff;" dir="ltr"><span style="color: #696969;">// AndroidManifest.xml</span>
<span style="color: #808030;">&lt;</span>activity
<span style="color: #e34adc;">    android:</span>name<span style="color: #808030;">=</span><span style="color: #800000;">"</span><span style="color: #0000e6;">ir.tapsell.sdk.TapsellAdActivity</span><span style="color: #800000;">"</span>
<span style="color: #e34adc;">    android:</span>label<span style="color: #808030;">=</span><span style="color: #800000;">"</span><span style="color: #0000e6;">TapsellAdActivity</span><span style="color: #800000;">"</span>
<span style="color: #e34adc;">    android:</span>configChanges<span style="color: #808030;">=</span><span style="color: #800000;">"</span><span style="color: #0000e6;">keyboard|keyboardHidden|orientation|screenSize</span><span style="color: #800000;">"</span>
<span style="color: #e34adc;">    android:</span>windowSoftInputMode<span style="color: #808030;">=</span><span style="color: #800000;">"</span><span style="color: #0000e6;">adjustPan</span><span style="color: #800000;">"</span><span style="color: #808030;">&gt;</span>
<span style="color: #808030;">&lt;</span><span style="color: #808030;">/</span>activity<span style="color: #808030;">&gt;
</span></pre>
همچنین مطمئن شوید persmission های زیر را دارد :
<pre style="color: #000000; background: #ffffff;" dir="ltr"><span style="color: #808030;">&lt;</span>uses<span style="color: #808030;">-</span>permission android<span style="color: #800080;">:</span>name<span style="color: #808030;">=</span><span style="color: #800000;">"</span><span style="color: #0000e6;">android.permission.INTERNET</span><span style="color: #800000;">"</span><span style="color: #808030;">/</span><span style="color: #808030;">&gt;</span>
<span style="color: #808030;">&lt;</span>uses<span style="color: #808030;">-</span>permission android<span style="color: #800080;">:</span>name<span style="color: #808030;">=</span><span style="color: #800000;">"</span><span style="color: #0000e6;">android.permission.ACCESS_NETWORK_STATE</span><span style="color: #800000;">"</span><span style="color: #808030;">/</span><span style="color: #808030;">&gt;</span></pre>
&nbsp;
</div>

<div dir="rtl" id="ios-project">
  <h1>راه‌اندازی پلاگین تپسل در پلتفرم iOS در Qt</h1>

  <h3>گام ۱: اضافه کردن پوشه SDK به پروژه Qt</h3>
پوشه TapsellSDKAndHelpers (دانلود شده در مراحل قبلی) را به محل پروژه خود اضافه کنید.
<h3>گام ۲: اضافه کردن مرحله build تپسل به پروژه Qt</h3>
در حالی که در حالت Build iOS هستید وارد قسمت تنظیمات پروژه شوید :
<br/>
<img class=" wp-image-2577 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2018/01/Screenshot-from-2018-01-06-18-11-45.png" alt="" width="53" height="237" />
<br/>
در قسمت Build Steps گزینه Add Build Step را انتخاب نموده و پس از آن گزینه Custom Process Step را انتخاب کنید. دقت کنید که این Build Step باید در بین ‌Build Step های qmake و Make باشد.(شما می توانید ترتیب این Build Step ها را مشخص کنید)

حال در قسمت Command کد زیر را وارد کنید:
<pre style="color: #000000; background: #ffffff;" dir="ltr">python</pre>
حال در قسمت Arguments کد زیر را وارد کنید:
<pre style="color: #000000; background: #ffffff;" dir="ltr">%{sourceDir}/TapsellSDKAndHelpers/embed.py %{buildDir}/&lt;YOUR_PROJECT_NAME&gt;.xcodeproj %{sourceDir}/TapsellSDKAndHelpers/TapsellSDKv3.framework</pre>
در قطعه کد بالا بجای &lt;YOUR_PROJECT_NAME&gt; اسم پروژه خود را قرار دهید و توجه کنید که شما باید پایتون را به صورت نصب شده بر روی سیستم خود داشته باشید.

در پایان Build Steps پروژه شما باید وضعیتی شبیه به تصویر مقابل داشته باشد:
<br/>
<img class="wp-image-2962 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2018/02/Screen-Shot-2018-02-21-at-4.56.51-PM-1.png" alt="" width="687" height="239" />
<br/>
</dir>

<div dir="rtl" id="interstitial">
  <h1>پیاده‌سازی تبلیغات ویدئویی (Interstitial/Rewarded Video) و بنری تمام صفحه (Interstitial Banner) در پروژه Qt</h1>
  <h3>گام ۱ : راه اندازی پروژه Qt</h3>
ابتدا به لینک زیر مراجعه کنید و پلاگین تپسل را به پروژه ی خود اضافه کنید :
<p style="text-align: center;"><a href="#qt-project"><button>راه اندازی پروژه</button></a></p>

<h3>گام ۲: دریافت کلید تپسل</h3>
وارد پنل مدیریت تپسل شده و با تعریف یک اپلیکیشن جدید با عنوان پکیج اپلیکیشن اندرویدی خود، یک کلید تپسل دریافت کنید.
<p style="text-align: center;"><a href="https://dashboard.tapsell.ir"><button>ورود به داشبورد تپسل</button></a></p>

<h3>گام ۳: شروع کار با SDK تپسل</h3>
ابتدا فایل هدر تپسل را include کنید :
<pre style="color: #000000; background: #ffffff;" dir="ltr"><span style="color: #004a43;">#</span><span style="color: #004a43;">include </span><span style="color: #800000;">"</span><span style="color: #40015a;">tapsell.h</span><span style="color: #800000;">"</span>
</pre>
برای مقداردهی اولیه ، تابع زیر را با ورودی کلید اپ خود صدا بزنید. ( دقت کنید که قبل از هر کاری این تابع را صدا بزنید در غیر این صورت تابع‌های دیگر کار نخواهند کرد)
<pre style="color: #000000; background: #ffffff;" dir="ltr">Tapsell<span style="color: #800080;">::</span>initialize<span style="color: #808030;">(</span>appKey<span style="color: #808030;">)</span><span style="color: #800080;">;</span>
</pre>
ورودی appKey کلید تپسلی است که در گام قبل از پنل تپسل دریافت کردید.
<h3>گام ۴: دریافت تبلیغ</h3>
نمایش یک تبلیغ ویدئویی در اپلیکیشن به دو صورت ممکن است صورت پذیرد. یک روش، نمایش تبلیغ بصورت stream می باشد. در این حالت، همزمان که کاربر درحال مشاهده بخشی از تبلیغ است، ادامه آن از اینترنت لود می گردد. ممکن است به دلیل کندی سرعت اینترنت، در این حالت کاربر با مکث های متعددی در هنگام دریافت و مشاهده تبلیغ مواجه شود. برای اینکه کاربر در هنگام نمایش تبلیغ منتظر نماند و تجربه کاربر در استفاده از اپلیکیشن بهبود یابد،روش دیگری نیز در SDK تپسل تعبیه شده است که در آن ابتدا فایل ویدئوی تبلیغاتی بطور کامل بارگذاری شده و سپس تبلیغ نمایش داده می شود.
همچنین در تپسل، تبلیغ می تواند در ناحیه‌های مختلفی از برنامه شما (مانند فروشگاه، انتهای هر مرحله، ابتدای مرحله جهت دریافت امتیاز دوبرابر، دریافت بنزین/لایف و ...) پخش شود. در تپسل به این ناحیه‌ها zone گفته می شود. ناحیه‌های هر اپلیکیشن در پنل تپسل تعریف می شوند.

با اجرای تابع زیر، می توانید یک درخواست تبلیغ به تپسل ارسال کرده و یک تبلیغ دریافت نمایید:
<pre style="color: #000000; background: #ffffff;" dir="ltr">Tapsell<span style="color: #800080;">::</span>requestAd<span style="color: #808030;">(QString</span> zoneId<span style="color: #808030;">,</span> <span style="color: #800000; font-weight: bold;">bool</span> isCached<span style="color: #808030;">,</span> <span style="color: #666616;">std</span><span style="color: #800080;">::</span>function<span style="color: #800080;">&lt;</span><span style="color: #800000; font-weight: bold;">void</span><span style="color: #808030;">(QString</span><span style="color: #808030;">)</span><span style="color: #800080;">&gt;</span> onAdAvailable<span style="color: #808030;">,</span>
                   <span style="color: #666616;">std</span><span style="color: #800080;">::</span>function<span style="color: #800080;">&lt;</span><span style="color: #800000; font-weight: bold;">void</span><span style="color: #808030;">(</span><span style="color: #808030;">)</span><span style="color: #800080;">&gt;</span> onNoAdAvailable<span style="color: #808030;">,</span> <span style="color: #666616;">std</span><span style="color: #800080;">::</span>function<span style="color: #800080;">&lt;</span><span style="color: #800000; font-weight: bold;">void</span><span style="color: #808030;">(</span><span style="color: #808030;">)</span><span style="color: #800080;">&gt;</span> onNoNetwork<span style="color: #808030;">,</span>
                   <span style="color: #666616;">std</span><span style="color: #800080;">::</span>function<span style="color: #800080;">&lt;</span><span style="color: #800000; font-weight: bold;">void</span><span style="color: #808030;">(QString</span><span style="color: #808030;">)</span><span style="color: #800080;">&gt;</span> onError<span style="color: #808030;">,</span> <span style="color: #666616;">std</span><span style="color: #800080;">::</span>function<span style="color: #800080;">&lt;</span><span style="color: #800000; font-weight: bold;">void</span><span style="color: #808030;">(QString</span><span style="color: #808030;">)</span><span style="color: #800080;">&gt;</span> onExpiring<span style="color: #808030;">)</span><span style="color: #800080;">;</span>
</pre>
هر درخواست شامل یک ورودی <code>zoneId</code> است که باید آن را از <a href="https://dashboard.tapsell.ir/">داشبورد تپسل</a> در صفحه اپلیکیشن خود دریافت کنید. دقت کنید که برای این پارامتر نباید از مقدار <code>null</code> استفاده کنید. ورودی <code>cached</code> یک متغیر <code>bool</code> (با مقدار True/False) می باشد که نشان می دهد که آیا تبلیغ باید ابتدا دانلود شده و سپس به کاربر نشان داده شود یا خیر.

<b>تنها در ناحیه‌هایی که کاربر با احتمال زیادی پس از باز کردن اپلیکیشن تبلیغ آن را مشاهده می‌کند، از تبلیغ Cached استفاده کنید. جهت توضیحات بیشتر درباره روش انتخاب متد دریافت مناسب، <a href="https://answers.tapsell.ir/?ht_kb=cached-vs-streamed">اینجا</a> را مطالعه کنید.</b>

نتیجه درخواست تبلیغ به تابع های callback ورودی بازگردانده می شود. یک نمونه پیاده سازی تابع های callback لازم در ادامه آمده است.

در onAdAvailable شناسه یک تبلیغ به شما برگردانده می شود که می بایست جهت نمایش تبلیغ آن را ذخیره نمایید. جهت توضیحات بیشتر به قطعه کد پیاده سازی اکشن که در ادامه آمده است توجه نمایید.
(در این مثال از lambda expression استفاده کردیم. از std::function هم می توانید استفاده کنید)
<pre style="margin: 0; line-height: 125%;" dir="ltr">Tapsell<span style="color: #666666;">::</span>requestAd(ZONE_ID, <span style="color: #008000;">false</span>, [](QString adId) {
            qDebug() <span style="color: #666666;">&lt;&lt;</span> <span style="color: #ba2121;">"onAdAvailable"</span>;
            AD_ID <span style="color: #666666;">=</span> adId;
        }, []() {
            qDebug() <span style="color: #666666;">&lt;&lt;</span> <span style="color: #ba2121;">"onNoAdAvailable"</span>;
        }, []() {
            qDebug() <span style="color: #666666;">&lt;&lt;</span> <span style="color: #ba2121;">"onNoNetwork"</span>;
        }, [](QString error) {
            qDebug() <span style="color: #666666;">&lt;&lt;</span> <span style="color: #ba2121;">"onError: "</span> <span style="color: #666666;">&lt;&lt;</span> error;
        }, [](QString adId) {
            qDebug() <span style="color: #666666;">&lt;&lt;</span> <span style="color: #ba2121;">"onExpiring "</span> <span style="color: #666666;">&lt;&lt;</span> adId;
        });
</pre>
توضیحات اکشن های مختلف و شرایط اجرا شدن آن ها در جدول ۱ آمده است.
<table style="text-align: center; border-collapse: collapse;" width="100%"><caption>جدول ۱ اکشن های دریافت نتیجه درخواست تبلیغ</caption>
<tbody>
<tr style="border-bottom: 1px solid #ddd;">
<th width="40%">تابع</th>
<th width="60%">توضیحات (زمان اجرا)</th>
</tr>
<tr style="background-color: #fefefe;">
<td dir="ltr" width="40%">onError(QString error)</td>
<td>هنگامی که هر نوع خطایی در پروسه‌ی دریافت تبلیغ بوجود بیاید</td>
</tr>
<tr style="background-color: #f2f2f2;">
<td dir="ltr" width="40%">onAdAvailable(QString adId)</td>
<td width="60%">زمانی که تبلیغ دریافت شده و آماده‌ی نمایش باشد.</td>
</tr>
<tr style="background-color: #fefefe;">
<td dir="ltr" width="40%">onNoAdAvailable()</td>
<td width="60%">در صورتی که تبلیغی برای نمایش وجود نداشته باشد.</td>
</tr>
<tr style="background-color: #f2f2f2;">
<td dir="ltr" width="40%">onNoNetwork()</td>
<td width="60%">زمانی که دسترسی به شبکه موجود نباشد.</td>
</tr>
<tr style="background-color: #fefefe;">
<td dir="ltr" width="40%">onExpiring(QString adId)</td>
<td width="60%">زمانی که تبلیغ منقضی شود. هر تبلیغ مدت زمان مشخصی معتبر است و در صورتی که تا قبل از آن نمایش داده نشود منقضی شده و دیگر قابل نمایش نخواهد بود.</td>
</tr>
</tbody>
</table>
<h3>گام ۵: نمایش تبلیغ</h3>
هر تبلیغ یک id از نوع string دارد. جهت نمایش تبلیغ، می‌توانید از دو تابع زیر استفاده نمایید (این تابع حداکثر یک بار برای هر تبلیغ قابل اجراست) :
<pre style="color: #000000; background: #ffffff;" dir="ltr">Tapsell<span style="color: #800080;">::</span>showAd<span style="color: #808030;">(</span><span style="color: #666616;">QString</span> zoneId<span style="color: #808030;">,</span> <span style="color: #666616;">QString</span> adId<span style="color: #808030;">,</span> <span style="color: #800000; font-weight: bold;">bool</span> back_disabled<span style="color: #808030;">,</span>
                <span style="color: #800000; font-weight: bold;">bool</span> immersive_mode<span style="color: #808030;">,</span> <span style="color: #800000; font-weight: bold;">int</span> rotation_mode<span style="color: #808030;">,</span> <span style="color: #800000; font-weight: bold;">bool</span> showExitDialog<span style="color: #808030;">)</span><span style="color: #800080;">;</span>
Tapsell<span style="color: #800080;">::</span>showAd<span style="color: #808030;">(</span><span style="color: #666616;">QString</span> zoneId<span style="color: #808030;">,</span> <span style="color: #666616;">QString</span> adId<span style="color: #808030;">,</span> <span style="color: #800000; font-weight: bold;">bool</span> back_disabled<span style="color: #808030;">,</span>
                <span style="color: #800000; font-weight: bold;">bool</span> immersive_mode<span style="color: #808030;">,</span> <span style="color: #800000; font-weight: bold;">int</span> rotation_mode<span style="color: #808030;">,</span> <span style="color: #800000; font-weight: bold;">bool</span> showExitDialog<span style="color: #808030;">,</span>
                <span style="color: #666616;">std</span><span style="color: #800080;">::</span>function<span style="color: #800080;">&lt;</span><span style="color: #800000; font-weight: bold;">void</span><span style="color: #808030;">(</span><span style="color: #666616;">QString</span><span style="color: #808030;">)</span><span style="color: #800080;">&gt;</span> onOpened<span style="color: #808030;">,</span> <span style="color: #666616;">std</span><span style="color: #800080;">::</span>function<span style="color: #800080;">&lt;</span><span style="color: #800000; font-weight: bold;">void</span><span style="color: #808030;">(</span><span style="color: #666616;">QString</span><span style="color: #808030;">)</span><span style="color: #800080;">&gt;</span> onClosed<span style="color: #808030;">)</span><span style="color: #800080;">;</span></pre>
<pre style="margin: 0; line-height: 125%;" dir="ltr">Tapsell<span style="color: #666666;">::</span>showAd(ZONE_ID, AD_ID, <span style="color: #008000;">false</span>, <span style="color: #008000;">false</span>, ROTATION_UNLOCKED, <span style="color: #008000;">true</span>,
            [](QString adId) {
                qDebug() <span style="color: #666666;">&lt;&lt;</span> <span style="color: #ba2121;">"onOpened"</span>;
            },
            [](QString adId) {
                qDebug() <span style="color: #666666;">&lt;&lt;</span> <span style="color: #ba2121;">"onClosed"</span>;
            });
</pre>
دو ورودی onOpened و onClosed از جنس تابع هستند و این callback ها زمان اجرا و پایان نمایش تبلیغ صدا زده می شوند.
<table style="text-align: center; border-collapse: collapse;" width="100%" cellpadding="6"><caption>جدول ۲ فیلدهای adOptions</caption>
<tbody>
<tr style="border-bottom: 1px solid #ddd;">
<th width="40%">متغیر (نوع)</th>
<th width="60%">توضیحات</th>
</tr>
<tr style="background-color: #fefefe;">
<td dir="ltr" width="40%">back_disabled (bool)</td>
<td width="60%">
<div align="right">در هنگام پخش تبلیغ دکمه‌ی بازگشت گوشی فعال باشد یا خیر</div></td>
</tr>
<tr style="background-color: #f2f2f2;">
<td dir="ltr" width="40%">immersive_mode(bool)</td>
<td width="60%">
<div align="right">فعال‌سازی حالت Immersive در هنگام پخش تبلیغ (فقط در اندروید)</div></td>
</tr>
<tr style="background-color: #fefefe;">
<td dir="ltr" width="40%">rotation_mode (int)</td>
<td width="60%">
<div align="right">تعیین وضعیت گوشی در هنگام پخش تبلیغ به یکی از سه حالت:</div>
<div align="left">ROTATION_LOCKED_PORTRAIT
ROTATION_LOCKED_LANDSCAPE
ROTATION_UNLOCKED
ROTATION_LOCKED_REVERSED_PORTRAIT
ROTATION_LOCKED_REVERSED_LANDSCAPE</div></td>
</tr>
<tr style="background-color: #f2f2f2;">
<td dir="ltr" width="40%">showExitDialog(bool)</td>
<td width="60%">
<div align="right">نمایش دیالوگ اخطار در هنگام بازگشت از تبلیغات جایزه‌دار</div></td>
</tr>
</tbody>
</table>
یک نمونه پیاده‌سازی درخواست تبلیغ در ادامه آمده است.
<pre style="margin: 0; line-height: 125%;" dir="ltr">Tapsell<span style="color: #666666;">::</span>showAd(ZONE_ID, AD_ID, <span style="color: #008000;">false</span>, <span style="color: #008000;">false</span>, ROTATION_UNLOCKED, <span style="color: #008000;">true</span>,
            [](QString adId) {
                qDebug() <span style="color: #666666;">&lt;&lt;</span> <span style="color: #ba2121;">"onOpened"</span>;
            },
            [](QString adId) {
                qDebug() <span style="color: #666666;">&lt;&lt;</span> <span style="color: #ba2121;">"onClosed"</span>;
            });</pre>
<h3>گام ۶: دریافت نتیجه نمایش تبلیغ</h3>
در صورتیکه در اپلیکیشن خود از تبلیغات جایزه‌دار استفاده می‌کنید، جهت دریافت نتیجه نمایش تبلیغ‌ها، باید یک اکشن مطابق زیر به SDK تپسل بدهید.
<pre style="margin: 0; line-height: 125%;" dir="ltr">Tapsell<span style="color: #666666;">::</span>setRewardListener([](QString zoneId, QString adId, <span style="color: #b00040;">bool</span> completed, <span style="color: #b00040;">bool</span> rewarded) {
        qDebug() <span style="color: #666666;">&lt;&lt;</span> <span style="color: #ba2121;">"Reward! "</span> <span style="color: #666666;">&lt;&lt;</span> completed <span style="color: #666666;">&lt;&lt;</span> <span style="color: #ba2121;">", "</span> <span style="color: #666666;">&lt;&lt;</span> rewarded;
    });
</pre>
پس از نمایش تبلیغ، اکشن onAdShowFinished اجرا می‌شود و نتیجه نمایش تبلیغ بازگردانده می‌شود. درصورتیکه تبلیغ نمایش داده شده جایزه‌دار باشد، متغیر rewarded در این شی دارای مقدار true خواهد بود. همچنین درصورتیکه تبلیغ تا انتها دیده شود، متغیر completed در ای شین دارای مقدار true خواهد بود.  در صورتی که تبلیغ جایزه‌دار باشد و مشاهده ویدئو تا انتها انجام شده باشد، باید جایزه درون برنامه (سکه، اعتبار، بنزین یا ...) را به کاربر بدهید.
<h3>نمونه پیاده‌سازی</h3>
یک نمونه پیاده‌سازی SDK تپسل در Qt در repository زیر آمده است.
<p style="text-align: center;"><a href="https://github.com/hermamitr/TapsellSDK_v3_Qt"><button>مشاهده پروژه نمونه</button></a></p>
لطفا نظرات خود درباره محتوای این فایل و مشکلاتی که در پیاده‌سازی SDK تپسل با آنها مواجه شدید را به ما اطلاع دهید.
</div>

<div dir="rtl" id="native-banner-implementaion">
  <h1>پیاده‌سازی تبلیغات بنری هم‌نما (Native Banner) در پروژه Qt</h1>
  <h3>گام ۱ : راه اندازی پروژه Qt</h3>
ابتدا به لینک زیر مراجعه کنید و پلاگین تپسل را به پروژه ی خود اضافه کنید :
<p style="text-align: center;"><a href="#qt-project"><button>راه اندازی پروژه</button></a></p>

<h3>گام ۲: دریافت کلید تپسل</h3>
وارد پنل مدیریت تپسل شده و با تعریف یک اپلیکیشن جدید با عنوان پکیج اپلیکیشن اندرویدی خود، یک کلید تپسل دریافت کنید.
<p style="text-align: center;"><a href="https://dashboard.tapsell.ir"><button>ورود به داشبورد تپسل</button></a></p>

<h3>گام ۳: شروع کار با SDK تپسل</h3>
ابتدا فایل هدر تپسل را include کنید :
<pre style="color: #000000; background: #ffffff;" dir="ltr"><span style="color: #004a43;">#</span><span style="color: #004a43;">include </span><span style="color: #800000;">"</span><span style="color: #40015a;">tapsell.h</span><span style="color: #800000;">"</span>
</pre>
برای مقداردهی اولیه ، تابع زیر را با ورودی کلید اپ خود صدا بزنید.
<pre style="color: #000000; background: #ffffff;" dir="ltr">Tapsell<span style="color: #800080;">::</span>initialize<span style="color: #808030;">(</span>appKey<span style="color: #808030;">)</span><span style="color: #800080;">;</span>
</pre>
ورودی appKey کلید تپسلی است که در گام قبل از پنل تپسل دریافت کردید.
<h3>گام ۴: دریافت تبلیغ</h3>
در تبلیغات هم‌نما، شما قادر هستید ویژگی‌های ظاهری هر یک از اجزای تبلیغ (اندازه، محل قرارگیری، رنگ فونت و…) را بصورتی که هماهنگ با محتوای اپلیکیشن شما باشد تعیین کنید.

برای این منظور، شما یک درخواست تبلیغ به SDK تپسل ارسال می کنید، محتوای یک تبلیغ هم‌نمای بنری را دریافت کنید و آن را به نحوه مورد نظر خود نمایش دهید.

جهت ارسال درخواست تبلیغ هم‌نما، از تابع زیر استفاده کنید.
<pre style="color: #000000; background: #ffffff;" dir="ltr"><span style="color: #000000;">Tapsell</span><span style="color: #800080;">::</span><span style="color: #000000;">requestNativeBannerAd</span><span style="color: #808030;">(</span><span style="color: #808030;"><span style="color: #666616;">QString</span></span><span style="color: #000000;"> zoneId</span><span style="color: #808030;">,</span><span style="color: #666616;">std</span><span style="color: #800080;">::</span><span style="color: #000000;">function</span><span style="color: #800080;">&lt;</span><span style="color: #800000; font-weight: bold;">void</span><span style="color: #808030;">(</span><span style="color: #666616;">QString</span><span style="color: #808030;">,</span><span style="color: #666616;">QString</span><span style="color: #808030;">,</span><span style="color: #666616;">QString</span><span style="color: #808030;">,</span><span style="color: #666616;">QString</span><span style="color: #808030;">,</span><span style="color: #666616;">QString</span><span style="color: #808030;">,</span><span style="color: #666616;">QString</span><span style="color: #808030;">,</span><span style="color: #666616;">QString</span><span style="color: #808030;">)</span><span style="color: #800080;">&gt;</span><span style="color: #000000;"> onAdAvailable</span><span style="color: #808030;">,</span>
<span style="color: #666616;">std</span><span style="color: #800080;">::</span><span style="color: #000000;">function</span><span style="color: #800080;">&lt;</span><span style="color: #800000; font-weight: bold;">void</span><span style="color: #808030;">(</span><span style="color: #808030;">)</span><span style="color: #800080;">&gt;</span><span style="color: #000000;"> onNoAdAvailable</span><span style="color: #808030;">,</span><span style="color: #666616;">std</span><span style="color: #800080;">::</span><span style="color: #000000;">function</span><span style="color: #800080;">&lt;</span><span style="color: #800000; font-weight: bold;">void</span><span style="color: #808030;">(</span><span style="color: #808030;">)</span><span style="color: #800080;">&gt;</span><span style="color: #000000;"> onNoNetwork</span><span style="color: #808030;">,</span><span style="color: #666616;">std</span><span style="color: #800080;">::</span><span style="color: #000000;">function</span><span style="color: #800080;">&lt;</span><span style="color: #800000; font-weight: bold;">void</span><span style="color: #808030;">(</span><span style="color: #666616;">QString</span><span style="color: #808030;">)</span><span style="color: #800080;">&gt;</span><span style="color: #000000;"> onError</span><span style="color: #808030;">)</span><span style="color: #800080;">;</span></pre>
ورودی zoneId، شناسه تبلیغ‌گاه از نوع بنری هم‌نما است که باید آن را از <a href="https://dashboard.tapsell.ir/">داشبورد تپسل</a> دریافت کنید.

نتیجه درخواست تبلیغ به تابع‌های ورودی بازگردانده می شود. یک نمونه پیاده سازی تابع‌های لازم در ادامه آمده است.
<pre style="color: #000000; background: #ffffff;" dir="ltr">Tapsell<span style="color: #800080;">:</span><span style="color: #800080;">:</span>requestNativeBannerAd<span style="color: #808030;">(</span>NATIVE_BANNER_ZONEID<span style="color: #808030;">,</span>
        <span style="color: #808030;">[</span><span style="color: #808030;">&amp;</span><span style="color: #808030;">]</span><span style="color: #808030;">(</span>QString adId<span style="color: #808030;">,</span>QString title<span style="color: #808030;">,</span> QString description<span style="color: #808030;">,</span> QString iconUrl<span style="color: #808030;">,</span>
                                   QString ctaText<span style="color: #808030;">,</span> QString portraitUrl<span style="color: #808030;">,</span> QString landscapeUrl<span style="color: #808030;">)</span> <span style="color: #800080;">{</span>
        qDebug<span style="color: #808030;">(</span><span style="color: #808030;">)</span> <span style="color: #808030;">&lt;&lt;</span> <span style="color: #800000;">"</span><span style="color: #0000e6;">onNativeBannerAdAvailable</span><span style="color: #800000;">"</span><span style="color: #800080;">;</span>
        <span style="color: #800080;">}</span><span style="color: #808030;">,</span> <span style="color: #808030;">[</span><span style="color: #808030;">]</span><span style="color: #808030;">(</span><span style="color: #808030;">)</span><span style="color: #800080;">{</span>
        qDebug<span style="color: #808030;">(</span><span style="color: #808030;">)</span> <span style="color: #808030;">&lt;&lt;</span> <span style="color: #800000;">"</span><span style="color: #0000e6;">onNoNativeBannerAdAvailable</span><span style="color: #800000;">"</span><span style="color: #800080;">;</span>
        <span style="color: #800080;">}</span><span style="color: #808030;">,</span> <span style="color: #808030;">[</span><span style="color: #808030;">]</span><span style="color: #808030;">(</span><span style="color: #808030;">)</span><span style="color: #800080;">{</span>
        qDebug<span style="color: #808030;">(</span><span style="color: #808030;">)</span> <span style="color: #808030;">&lt;&lt;</span> <span style="color: #800000;">"</span><span style="color: #0000e6;">onNoNetwork</span><span style="color: #800000;">"</span><span style="color: #800080;">;</span>
        <span style="color: #800080;">}</span><span style="color: #808030;">,</span> <span style="color: #808030;">[</span><span style="color: #808030;">]</span><span style="color: #808030;">(</span>QString error<span style="color: #808030;">)</span> <span style="color: #800080;">{</span>
        qDebug<span style="color: #808030;">(</span><span style="color: #808030;">)</span> <span style="color: #808030;">&lt;&lt;</span> <span style="color: #800000;">"</span><span style="color: #0000e6;">onError: </span><span style="color: #800000;">"</span> <span style="color: #808030;">&lt;&lt;</span> error<span style="color: #800080;">;</span>
        <span style="color: #800080;">}</span><span style="color: #808030;">)</span><span style="color: #800080;">;</span>
</pre>
<h3 id="گام-۴-نمایش-تبلیغ">گام ۵: نمایش تبلیغ</h3>
برای نمایش تبلیغ، می‌بایست از داده های موجود در تابع onAdAvailable استفاده کنید. توضیح این داده ها در جدول زیر آمده است :
<table width="100%"><caption>جدول ۱ داده های تابع onAdAvailable</caption>
<tbody>
<tr>
<th width="40%">مشخصه</th>
<th width="60%">توضیحات</th>
</tr>
<tr>
<td width="40%">adId</td>
<td>شناسه تبلیغ</td>
</tr>
<tr>
<td width="40%">title</td>
<td>عنوان تبلیغ</td>
</tr>
<tr>
<td width="40%">description</td>
<td width="60%">توضیحات تبلیغ</td>
</tr>
<tr>
<td width="40%">ctaText</td>
<td width="60%">متن دعوت کننده از کاربر به کلیک/نصب</td>
</tr>
<tr>
<td width="40%">portraitUrl</td>
<td width="60%">لینک تصویر بنر تبلیغ (عمودی)</td>
</tr>
<tr>
<td width="40%">landscapeUrl</td>
<td width="60%">لینک تصویر بنر تبلیغ (افقی)</td>
</tr>
<tr>
<td width="40%">iconUrl</td>
<td width="60%">لینک آیکون تبلیغ</td>
</tr>
</tbody>
</table>
دقت کنید که تبلیغ‌ها ممکن است هردو بنر عمودی و افقی را نداشته باشند.

&nbsp;

در زمان نمایش تبلیغ، باید تابع <code>onNativeBannerAdShown</code> از کلاس <code>Tapsell</code> را فراخوانی کنید ؛ این تابع یک رشته به عنوان ورودی می‌گیرد که شناسه مربوط به تبلیغی است که نمایش داده شده است.
<pre dir="ltr">Tapsell::onNativeBannerAdShown(adId);</pre>
<h3 id="گام-۵-باز-کردن-تبلیغ">گام ۶: باز کردن تبلیغ</h3>
برای باز کردن تبلیغ، هنگامی که کاربر روی آن کلیک می‌کند، از تابع زیر استفاده کنید. این تابع یک رشته به عنوان ورودی می‌گیرد که شناسه مربوط به تبلیغی است که روی آن کلیک شده است.
<pre dir="ltr">Tapsell::onNativeBannerAdClicked(adId);</pre>
<h3>نمونه پیاده‌سازی</h3>
یک نمونه پیاده‌سازی SDK تپسل در Qt در repository زیر آمده است.
<p style="text-align: center;"><a href="https://github.com/hermamitr/TapsellSDK_v3_Qt"><button>مشاهده پروژه نمونه</button></a></p>
لطفا نظرات خود درباره محتوای این فایل و مشکلاتی که در پیاده‌سازی SDK تپسل با آنها مواجه شدید را به ما اطلاع دهید.
</div>

<div dir="rtl" id="native-video-implementation">
  <h1>پیاده‌سازی تبلیغات ویدیویی هم‌نما (Native Video) در پروژه Qt</h1>

  <h3>گام ۱ : راه اندازی پروژه Qt</h3>
ابتدا به لینک زیر مراجعه کنید و پلاگین تپسل را به پروژه ی خود اضافه کنید :
<p style="text-align: center;"><a href="#qt-project"><button>راه اندازی پروژه</button></a></p>

<h3>گام ۲: دریافت کلید تپسل</h3>
وارد پنل مدیریت تپسل شده و با تعریف یک اپلیکیشن جدید با عنوان پکیج اپلیکیشن اندرویدی خود، یک کلید تپسل دریافت کنید.
<p style="text-align: center;"><a href="https://dashboard.tapsell.ir"><button>ورود به داشبورد تپسل</button></a></p>

<h3>گام ۳: شروع کار با SDK تپسل</h3>
ابتدا فایل هدر تپسل را include کنید :
<pre style="color: #000000; background: #ffffff;" dir="ltr"><span style="color: #004a43;">#</span><span style="color: #004a43;">include </span><span style="color: #800000;">"</span><span style="color: #40015a;">tapsell.h</span><span style="color: #800000;">"</span>
</pre>
برای مقداردهی اولیه ، تابع زیر را با ورودی کلید اپ خود صدا بزنید.
<pre style="color: #000000; background: #ffffff;" dir="ltr">Tapsell<span style="color: #800080;">::</span>initialize<span style="color: #808030;">(</span>appKey<span style="color: #808030;">)</span><span style="color: #800080;">;</span>
</pre>
ورودی appKey کلید تپسلی است که در گام قبل از پنل تپسل دریافت کردید.
<h3>گام ۴: دریافت تبلیغ</h3>
در تبلیغات هم‌نما، شما قادر هستید ویژگی‌های ظاهری هر یک از اجزای تبلیغ (اندازه، محل قرارگیری، رنگ فونت و…) را بصورتی که هماهنگ با محتوای اپلیکیشن شما باشد تعیین کنید.

برای این منظور، شما یک درخواست تبلیغ به SDK تپسل ارسال می کنید، محتوای یک تبلیغ هم‌نمای ویدیویی را دریافت کنید و آن را به نحوه مورد نظر خود نمایش دهید.

جهت ارسال درخواست تبلیغ هم‌نما، از تابع زیر استفاده کنید.
<pre style="color: #000000; background: #ffffff;" dir="ltr"><span style="color: #000000;">Tapsell</span><span style="color: #800080;">::</span><span style="color: #000000;">requestNativeBannerAd</span><span style="color: #808030;">(</span><span style="color: #808030;"><span style="color: #666616;">QString</span></span><span style="color: #000000;"> zoneId</span><span style="color: #808030;">,</span><span style="color: #666616;">std</span><span style="color: #800080;">::</span><span style="color: #000000;">function</span><span style="color: #800080;">&lt;</span><span style="color: #800000; font-weight: bold;">void</span><span style="color: #808030;">(</span><span style="color: #666616;">QString</span><span style="color: #808030;">,</span><span style="color: #666616;">QString</span><span style="color: #808030;">,</span><span style="color: #666616;">QString</span><span style="color: #808030;">,</span><span style="color: #666616;">QString</span><span style="color: #808030;">,</span><span style="color: #666616;">QString</span><span style="color: #808030;">,</span><span style="color: #666616;">QString</span><span style="color: #808030;">)</span><span style="color: #800080;">&gt;</span><span style="color: #000000;"> onAdAvailable</span><span style="color: #808030;">,</span>
<span style="color: #666616;">std</span><span style="color: #800080;">::</span><span style="color: #000000;">function</span><span style="color: #800080;">&lt;</span><span style="color: #800000; font-weight: bold;">void</span><span style="color: #808030;">(</span><span style="color: #808030;">)</span><span style="color: #800080;">&gt;</span><span style="color: #000000;"> onNoAdAvailable</span><span style="color: #808030;">,</span><span style="color: #666616;">std</span><span style="color: #800080;">::</span><span style="color: #000000;">function</span><span style="color: #800080;">&lt;</span><span style="color: #800000; font-weight: bold;">void</span><span style="color: #808030;">(</span><span style="color: #808030;">)</span><span style="color: #800080;">&gt;</span><span style="color: #000000;"> onNoNetwork</span><span style="color: #808030;">,</span><span style="color: #666616;">std</span><span style="color: #800080;">::</span><span style="color: #000000;">function</span><span style="color: #800080;">&lt;</span><span style="color: #800000; font-weight: bold;">void</span><span style="color: #808030;">(</span><span style="color: #666616;">QString</span><span style="color: #808030;">)</span><span style="color: #800080;">&gt;</span><span style="color: #000000;"> onError</span><span style="color: #808030;">)</span><span style="color: #800080;">;</span></pre>
ورودی zoneId، شناسه تبلیغ‌گاه از نوع ویدیویی هم‌نما است که باید آن را از <a href="https://dashboard.tapsell.ir/">داشبورد تپسل</a> دریافت کنید.

نتیجه درخواست تبلیغ به تابع‌های ورودی بازگردانده می شود. یک نمونه پیاده سازی تابع‌های لازم در ادامه آمده است.
<pre style="color: #000000; background: #ffffff;" dir="ltr">Tapsell<span style="color: #800080;">:</span><span style="color: #800080;">:</span>requestNativeVideoAd<span style="color: #808030;">(</span>NATIVE_VIDEO_ZONEID<span style="color: #808030;">,</span>
        <span style="color: #808030;">[</span><span style="color: #808030;">&amp;</span><span style="color: #808030;">]</span><span style="color: #808030;">(</span>QString adId<span style="color: #808030;">,</span>QString title<span style="color: #808030;">,</span> QString description<span style="color: #808030;">,</span> QString iconUrl<span style="color: #808030;">,</span>
                                   QString ctaText<span style="color: #808030;">,</span> QString videoUrl<span style="color: #808030;">)</span> <span style="color: #800080;">{</span>
        qDebug<span style="color: #808030;">(</span><span style="color: #808030;">)</span> <span style="color: #808030;">&lt;&lt;</span> <span style="color: #800000;">"</span><span style="color: #0000e6;">onNativeVideoAdAvailable</span><span style="color: #800000;">"</span><span style="color: #800080;">;</span>
        <span style="color: #800080;">}</span><span style="color: #808030;">,</span> <span style="color: #808030;">[</span><span style="color: #808030;">]</span><span style="color: #808030;">(</span><span style="color: #808030;">)</span><span style="color: #800080;">{</span>
        qDebug<span style="color: #808030;">(</span><span style="color: #808030;">)</span> <span style="color: #808030;">&lt;&lt;</span> <span style="color: #800000;">"</span><span style="color: #0000e6;">onNoNativeVideoAdAvailable</span><span style="color: #800000;">"</span><span style="color: #800080;">;</span>
        <span style="color: #800080;">}</span><span style="color: #808030;">,</span> <span style="color: #808030;">[</span><span style="color: #808030;">]</span><span style="color: #808030;">(</span><span style="color: #808030;">)</span><span style="color: #800080;">{</span>
        qDebug<span style="color: #808030;">(</span><span style="color: #808030;">)</span> <span style="color: #808030;">&lt;&lt;</span> <span style="color: #800000;">"</span><span style="color: #0000e6;">onNoNetwork</span><span style="color: #800000;">"</span><span style="color: #800080;">;</span>
        <span style="color: #800080;">}</span><span style="color: #808030;">,</span> <span style="color: #808030;">[</span><span style="color: #808030;">]</span><span style="color: #808030;">(</span>QString error<span style="color: #808030;">)</span> <span style="color: #800080;">{</span>
        qDebug<span style="color: #808030;">(</span><span style="color: #808030;">)</span> <span style="color: #808030;">&lt;&lt;</span> <span style="color: #800000;">"</span><span style="color: #0000e6;">onError: </span><span style="color: #800000;">"</span> <span style="color: #808030;">&lt;&lt;</span> error<span style="color: #800080;">;</span>
        <span style="color: #800080;">}</span><span style="color: #808030;">)</span><span style="color: #800080;">;</span>
</pre>
<h3 id="گام-۴-نمایش-تبلیغ">گام ۵: نمایش تبلیغ</h3>
برای نمایش تبلیغ، می‌بایست از داده های موجود در تابع onAdAvailable استفاده کنید. توضیح این داده ها در جدول زیر آمده است :
<table width="100%"><caption>جدول ۱ داده های تابع onAdAvailable</caption>
<tbody>
<tr>
<th width="40%">مشخصه</th>
<th width="60%">توضیحات</th>
</tr>
<tr>
<td width="40%">adId</td>
<td>شناسه تبلیغ</td>
</tr>
<tr>
<td width="40%">title</td>
<td>عنوان تبلیغ</td>
</tr>
<tr>
<td width="40%">description</td>
<td width="60%">توضیحات تبلیغ</td>
</tr>
<tr>
<td width="40%">ctaText</td>
<td width="60%">متن دعوت کننده از کاربر به کلیک/نصب</td>
</tr>
<tr>
<td width="40%">videoUrl</td>
<td width="60%">لینک ویدیو تبلیغ</td>
</tr>
<tr>
<td width="40%">iconUrl</td>
<td width="60%">لینک آیکون تبلیغ</td>
</tr>
</tbody>
</table>
دقت کنید که تبلیغ‌ها ممکن است هردو بنر عمودی و افقی را نداشته باشند.

زمانی که پخش ویدیو تمام شد، باید تابع <code>onNativeVideoAdShown</code> از کلاس <code>Tapsell</code> را فراخوانی کنید ؛ این تابع یک رشته به عنوان ورودی می‌گیرد که شناسه مربوط به تبلیغی است که نمایش داده شده است.
<pre dir="ltr">Tapsell::onNativeVideoAdShown(adId);</pre>
<h3 id="گام-۵-باز-کردن-تبلیغ">گام ۶: باز کردن تبلیغ</h3>
برای باز کردن تبلیغ، هنگامی که کاربر روی آن کلیک می‌کند، از تابع زیر استفاده کنید. این تابع یک رشته به عنوان ورودی می‌گیرد که شناسه مربوط به تبلیغی است که روی آن کلیک شده است.
<pre dir="ltr">Tapsell::onNativeVideoAdClicked(adId);</pre>
<h3>نمونه پیاده‌سازی</h3>
یک نمونه پیاده‌سازی SDK تپسل در Qt در repository زیر آمده است.
<p style="text-align: center;"><a href="https://github.com/hermamitr/TapsellSDK_v3_Qt"><button>مشاهده پروژه نمونه</button></a></p>
لطفا نظرات خود درباره محتوای این فایل و مشکلاتی که در پیاده‌سازی SDK تپسل با آنها مواجه شدید را به ما اطلاع دهید.
</div>

<div dir="rtl" id="standard-banner">
  <h1>پیاده‌سازی تبلیغات بنری استاندارد در پروژه Qt</h1>

  <h3>گام ۱ : راه اندازی پروژه Qt</h3>
ابتدا به لینک زیر مراجعه کنید و پلاگین تپسل را به پروژه ی خود اضافه کنید :
<p style="text-align: center;"><a href="#qt-project"><button>راه اندازی پروژه</button></a></p>

<h3>گام ۲: دریافت کلید تپسل</h3>
وارد پنل مدیریت تپسل شده و با تعریف یک اپلیکیشن جدید با عنوان پکیج اپلیکیشن اندرویدی خود، یک کلید تپسل دریافت کنید.
<p style="text-align: center;"><a href="https://dashboard.tapsell.ir"><button>ورود به داشبورد تپسل</button></a></p>

<h3>گام ۳: شروع کار با SDK تپسل</h3>
ابتدا فایل هدر تپسل را include کنید :
<pre style="color: #000000; background: #ffffff;" dir="ltr"><span style="color: #004a43;">#</span><span style="color: #004a43;">include </span><span style="color: #800000;">"</span><span style="color: #40015a;">tapsell.h</span><span style="color: #800000;">"</span>
</pre>
برای مقداردهی اولیه ، تابع زیر را با ورودی کلید اپ خود صدا بزنید.
<pre style="color: #000000; background: #ffffff;" dir="ltr">Tapsell<span style="color: #800080;">::</span>initialize<span style="color: #808030;">(</span>appKey<span style="color: #808030;">)</span><span style="color: #800080;">;</span>
</pre>
ورودی appKey کلید تپسلی است که در گام قبل از پنل تپسل دریافت کردید.
<h3>گام ۴: دریافت تبلیغ</h3>
جهت نمایش بنر استاندارد، باید محلی برای نمایش آن در صفحه در نظر بگیرید. بنر استاندارد، دارای سایزهای استانداردی است که در SDK تپسل مشخص شده اند. جهت نمایش بنر، از توابع زیر استفاده کنید:
<pre dir="ltr">Tapsell::requestStandardBannerAd(zoneId, bannerType, horizontalGravity, verticalGravity);
Tapsell::requestStandardBannerAd(zoneId, bannerType, horizontalGravity, verticalGravity, 
                                std::function&lt;void()&gt; onStandardBannerNoAdAvailable, std::function&lt;void()&gt; onStandardBannerNoNetwork, 
                                std::function&lt;void(std::string)&gt; onStandardBannerError, std::function&lt;void()&gt; onStandardBannerRequestFilled, 
                                std::function&lt;void()&gt; onStandardBannerHideBannerView);</pre>
مقدار zoneId کلیدی ست که بعد از ساخت اپلیکیشن در پنل و ثبت یک zone از نوع بنری استاندارد دریافت میکنید.

تابع دوم داری پارامترهای اضافی می‌باشد. این پارامترهای اضافی توابع callback هستند که شرح آنها در جدول زیر آمده است :
<table style="text-align: center; border-collapse: collapse;" width="100%"><caption>جدول ۱ اکشن های دریافت نتیجه درخواست تبلیغ</caption>
<tbody>
<tr style="border-bottom: 1px solid #ddd;">
<th width="40%">تابع</th>
<th width="60%">توضیحات (زمان اجرا)</th>
</tr>
<tr style="background-color: #fefefe;">
<td dir="ltr" width="40%">onStandardBannerError(std::string error)</td>
<td>هنگامی که هر نوع خطایی در پروسه‌ی دریافت تبلیغ بوجود بیاید</td>
</tr>
<tr style="background-color: #f2f2f2;">
<td dir="ltr" width="40%">onStandardBannerRequestFilled()</td>
<td width="60%">زمانی که تبلیغ دریافت شده و نمایش داده شده باشد.</td>
</tr>
<tr style="background-color: #fefefe;">
<td dir="ltr" width="40%">onStandardBannerNoAdAvailable()</td>
<td width="60%">در صورتی که تبلیغی برای نمایش وجود نداشته باشد.</td>
</tr>
<tr style="background-color: #f2f2f2;">
<td dir="ltr" width="40%">onStandardBannerNoNetwork()</td>
<td width="60%">زمانی که دسترسی به شبکه موجود نباشد.</td>
</tr>
<tr style="background-color: #fefefe;">
<td dir="ltr" width="40%">onStandardBannerHideBannerView()</td>
<td width="60%">زمانی که کاربر تبلیغ را ببندد. (روی ضربدر تبلیغ کلیک کند)</td>
</tr>
</tbody>
</table>
ورودی BannerType اندازه های مختلف را بیان میکند و شامل مقادیر زیر می‌باشد :
<table style="text-align: center; border-collapse: collapse;" width="100%" cellpadding="6"><caption>جدول ۲ مقادیر مختلف پارامتر bannerType</caption>
<tbody>
<tr style="border-bottom: 1px solid #ddd;">
<th width="40%">مقدار</th>
<th width="60%">ابعاد و نام استاندارد</th>
</tr>
<tr style="background-color: #fefefe;">
<td width="40%">‌BANNER_320x50</td>
<td width="60%">عرض ۳۲۰ - ارتفاع ۵۰ (mobile banner)</td>
</tr>
<tr style="background-color: #f2f2f2;">
<td width="40%">BANNER_320x100</td>
<td width="60%">عرض ۳۲۰ - ارتفاع  ۱۰۰ (large mobile banner)</td>
</tr>
<tr style="background-color: #fefefe;">
<td width="40%">BANNER_250x250</td>
<td width="60%">عرض ۲۵۰ - ارتفاع ۲۵۰ (square)</td>
</tr>
<tr style="background-color: #f2f2f2;">
<td width="40%">BANNER_300x250</td>
<td width="60%">عرض ۳۰۰ - ارتفاع ۲۵۰ (medium rectangle)</td>
</tr>
</tbody>
</table>
ورودی horizontalGravity نشان میدهد که آیا تبلیغ، بالا یا پایین صفحه باشد و شامل TOP, BOTTOM می باشد،

همچنین verticalGravity بیان میکند که تبلیغ از جهت عرضی در کجای صفحه باشد و میتواند شامل مقادیر LEFT, RIGHT ,CENTER باشد. یک نمونه پیاده سازی توابع بالا به شکل زیر است:
<pre dir="ltr">Tapsell::requestStandardBannerAd("5a44aa6565a77100013d5fb3", BANNER_320x50, BOTTOM, CENTER);
Tapsell::requestStandardBannerAd(STANDARD_BANNER_ZONEID,
		BANNER_320x100, BOTTOM,
		CENTER,
		[](){
		qDebug() &lt;&lt; "onStandardBannerNoAdAvailable" &lt;&lt; endl;
		}, [](){
		qDebug() &lt;&lt; "onStandardBannerNoNetwork" &lt;&lt; endl;
		}, [](QString error){
		qDebug() &lt;&lt; "onStandardBannerError: " &lt;&lt; error &lt;&lt; endl;
		}, [](){
		qDebug() &lt;&lt; "onStandardBannerRequestFilled" &lt;&lt; endl;
		}, [](){
		qDebug() &lt;&lt; "onStandardBannerHideBannerView" &lt;&lt; endl;
		});
</pre>
<h3>نمونه پیاده‌سازی</h3>
یک نمونه پیاده‌سازی SDK تپسل در Qt در repository زیر آمده است.
<p style="text-align: center;"><a href="https://github.com/hermamitr/TapsellSDK_v3_Qt"><button>مشاهده پروژه نمونه</button></a></p>
لطفا نظرات خود درباره محتوای این فایل و مشکلاتی که در پیاده‌سازی SDK تپسل با آنها مواجه شدید را به ما اطلاع دهید.
</div>

</div>
