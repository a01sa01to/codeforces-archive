from get_chrome_driver import GetChromeDriver
from selenium import webdriver

def driver_init() -> webdriver.Chrome:
    # Chromeをインストール
    get_driver = GetChromeDriver()
    get_driver.install()
    # ChromeDriverを初期化
    options = webdriver.ChromeOptions()
    options.add_argument("--no-sandbox")
    options.add_argument("--single-process")
    options.add_argument("--disable-setuid-sandbox")
    # もしDebugでなければ、画面に表示しなくてもいい
    options.add_argument('--headless')
    return webdriver.Chrome(options=options)