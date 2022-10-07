#include "get_stock_list.h"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

stock_map get_stock_list() {
  std::map<std::string, std::string> params = {
      {"北向资金",
       "------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"type\"\r\n\r\nRPTA_APP_STOCKSELECT\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"sty\"\r\n\r\nSECUCODE,SECURITY_CODE,SECURITY_NAME_ABBR,NEW_"
       "PRICE,CHANGE_RATE,\r\n------WebKitFormBoundary\r\nContent-Disposition: "
       "form-data; name=\"filter\"\r\n\r\n(HOLD_RATIO_RANK "
       "<=50)\r\n------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"p\"\r\n\r\n1\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; "
       "name=\"ps\"\r\n\r\n100\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"sr\"\r\n\r\n-1\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"st\"\r\n\r\nCHANGE_RATE\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"source\"\r\n\r\nSELECT_SECURITIES\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"client\"\r\n\r\nAPP\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"ct\"\r\n\r\n\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; name=\"ut\"\r\n\r\n\r\n------WebKitFormBoundary--\r\n"},
      {"估值三低",
       "------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"type\"\r\n\r\nRPTA_APP_STOCKSELECT\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"sty\"\r\n\r\nSECUCODE,SECURITY_CODE,SECURITY_NAME_ABBR,NEW_"
       "PRICE,CHANGE_RATE,DUNMPTON_STRATEGY\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"filter\"\r\n\r\n(DUNMPTON_STRATEGY=\"1\")\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"p\"\r\n\r\n1\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; "
       "name=\"ps\"\r\n\r\n300\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"sr\"\r\n\r\n-1\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"st\"\r\n\r\nCHANGE_RATE\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"source\"\r\n\r\nSELECT_SECURITIES\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"client\"\r\n\r\nAPP\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"ct\"\r\n\r\n\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; name=\"ut\"\r\n\r\n\r\n------WebKitFormBoundary--\r\n"},
      {"机构主力关注",
       "------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"type\"\r\n\r\nRPTA_APP_STOCKSELECT\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"sty\"\r\n\r\nSECUCODE,SECURITY_CODE,SECURITY_NAME_ABBR,NEW_"
       "PRICE,CHANGE_RATE,CHANGERATE_3DAYS,NETINFLOW_5DAYS,ORG_RATING\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"filter\"\r\n\r\n(CHANGERATE_3DAYS>=5)(NETINFLOW_5DAYS>=0)(ORG_"
       "RATING IN (\"买入\",\"买入-\") "
       ")\r\n------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"p\"\r\n\r\n1\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; "
       "name=\"ps\"\r\n\r\n300\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"sr\"\r\n\r\n-1\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"st\"\r\n\r\nCHANGE_RATE\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"source\"\r\n\r\nSELECT_SECURITIES\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"client\"\r\n\r\nAPP\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"ct\"\r\n\r\n\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; name=\"ut\"\r\n\r\n\r\n------WebKitFormBoundary--\r\n"},
      {"高成长优选",
       "------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"type\"\r\n\r\nRPTA_APP_STOCKSELECT\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"sty\"\r\n\r\nSECUCODE,SECURITY_CODE,SECURITY_NAME_ABBR,NEW_"
       "PRICE,CHANGE_RATE,NETPROFIT_YOY_RATIO,PE9,PS9,TOI_YOY_RATIO\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"filter\"\r\n\r\n(NETPROFIT_YOY_RATIO>=30)(NETPROFIT_YOY_RATIO<="
       "1000)(PE9>=0)(PE9<=50)(PS9>=0)(PS9<=2)(TOI_YOY_RATIO>=30)(TOI_YOY_"
       "RATIO<=1000)\r\n------WebKitFormBoundary\r\nContent-Disposition: "
       "form-data; "
       "name=\"p\"\r\n\r\n1\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; "
       "name=\"ps\"\r\n\r\n200\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"sr\"\r\n\r\n-1\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"st\"\r\n\r\nCHANGE_RATE\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"source\"\r\n\r\nSELECT_SECURITIES\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"client\"\r\n\r\nAPP\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"ct\"\r\n\r\n\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; name=\"ut\"\r\n\r\n\r\n------WebKitFormBoundary--\r\n"},
      {"社保大量持股",
       "------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"type\"\r\n\r\nRPTA_APP_STOCKSELECT\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"sty\"\r\n\r\nSECUCODE,SECURITY_CODE,SECURITY_NAME_ABBR,NEW_"
       "PRICE,CHANGE_RATE,SOCIAL_STOCK_HOLD\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"filter\"\r\n\r\n(SOCIAL_STOCK_HOLD=\"1\")\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"p\"\r\n\r\n1\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; "
       "name=\"ps\"\r\n\r\n400\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"sr\"\r\n\r\n-1\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"st\"\r\n\r\nCHANGE_RATE\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"source\"\r\n\r\nSELECT_SECURITIES\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"client\"\r\n\r\nAPP\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"ct\"\r\n\r\n\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; name=\"ut\"\r\n\r\n\r\n------WebKitFormBoundary--\r\n"},
      {"彼得林奇",
       "------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"type\"\r\n\r\nRPTA_APP_STOCKSELECT\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"sty\"\r\n\r\nSECUCODE,SECURITY_CODE,SECURITY_NAME_ABBR,NEW_"
       "PRICE,CHANGE_RATE,PETERLYNCH_STOCK\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"filter\"\r\n\r\n(PETERLYNCH_STOCK=\"1\")\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"p\"\r\n\r\n1\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; "
       "name=\"ps\"\r\n\r\n400\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"sr\"\r\n\r\n-1\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"st\"\r\n\r\nCHANGE_RATE\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"source\"\r\n\r\nSELECT_SECURITIES\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"client\"\r\n\r\nAPP\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"ct\"\r\n\r\n\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; name=\"ut\"\r\n\r\n\r\n------WebKitFormBoundary--\r\n"},
      {"精选白马",
       "------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"type\"\r\n\r\nRPTA_APP_STOCKSELECT\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"sty\"\r\n\r\nSECUCODE,SECURITY_CODE,SECURITY_NAME_ABBR,NEW_"
       "PRICE,CHANGE_RATE,BASIC_EPS,NETPROFIT_YOY_RATIO,PE9,ROE_WEIGHT,TOI_YOY_"
       "RATIO\r\n------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"filter\"\r\n\r\n(BASIC_EPS>=0.5)(NETPROFIT_YOY_RATIO>=15)(PE9>="
       "0)(PE9<=40)(ROE_WEIGHT>=15)(TOI_YOY_RATIO>=20)\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"p\"\r\n\r\n1\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; "
       "name=\"ps\"\r\n\r\n400\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"sr\"\r\n\r\n-1\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"st\"\r\n\r\nCHANGE_RATE\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"source\"\r\n\r\nSELECT_SECURITIES\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"client\"\r\n\r\nAPP\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"ct\"\r\n\r\n\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; name=\"ut\"\r\n\r\n\r\n------WebKitFormBoundary--\r\n"},
      {"高送转预期",
       "------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"type\"\r\n\r\nRPTA_APP_STOCKSELECT\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"sty\"\r\n\r\nSECUCODE,SECURITY_CODE,SECURITY_NAME_ABBR,NEW_"
       "PRICE,CHANGE_RATE,BASIC_EPS,BVPS,PER_CAPITAL_RESERVE,PER_UNASSIGN_"
       "PROFIT,TOTAL_MARKET_CAP\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"filter\"\r\n\r\n(BASIC_EPS>=0.5)(BVPS>5)(PER_CAPITAL_RESERVE>=3)"
       "(PER_UNASSIGN_PROFIT>=2)(TOTAL_MARKET_CAP<=20000000000)\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"p\"\r\n\r\n1\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; "
       "name=\"ps\"\r\n\r\n400\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"sr\"\r\n\r\n-1\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"st\"\r\n\r\nCHANGE_RATE\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"source\"\r\n\r\nSELECT_SECURITIES\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"client\"\r\n\r\nAPP\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"ct\"\r\n\r\n\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; name=\"ut\"\r\n\r\n\r\n------WebKitFormBoundary--\r\n"},
      {"格雷厄姆",
       "------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"type\"\r\n\r\nRPTA_APP_STOCKSELECT\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"sty\"\r\n\r\nSECUCODE,SECURITY_CODE,SECURITY_NAME_ABBR,NEW_"
       "PRICE,CHANGE_RATE,GRAHAM_STOCK\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"filter\"\r\n\r\n(GRAHAM_STOCK=\"1\")\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"p\"\r\n\r\n1\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; "
       "name=\"ps\"\r\n\r\n400\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"sr\"\r\n\r\n-1\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"st\"\r\n\r\nCHANGE_RATE\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"source\"\r\n\r\nSELECT_SECURITIES\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"client\"\r\n\r\nAPP\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"ct\"\r\n\r\n\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; name=\"ut\"\r\n\r\n\r\n------WebKitFormBoundary--\r\n"},
      {"绩优大盘股",
       "------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"type\"\r\n\r\nRPTA_APP_STOCKSELECT\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"sty\"\r\n\r\nSECUCODE,SECURITY_CODE,SECURITY_NAME_ABBR,NEW_"
       "PRICE,CHANGE_RATE,NETPROFIT_YOY_RATIO,PE9,ROE_WEIGHT,TOI_YOY_RATIO,"
       "TOTAL_MARKET_CAP\r\n------WebKitFormBoundary\r\nContent-Disposition: "
       "form-data; "
       "name=\"filter\"\r\n\r\n(NETPROFIT_YOY_RATIO>=5)(PE9>=0)(PE9<=30)(ROE_"
       "WEIGHT>=20)(TOI_YOY_RATIO>=20)(TOTAL_MARKET_CAP>50000000000)\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"p\"\r\n\r\n1\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; "
       "name=\"ps\"\r\n\r\n400\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"sr\"\r\n\r\n-1\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"st\"\r\n\r\nCHANGE_RATE\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"source\"\r\n\r\nSELECT_SECURITIES\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"client\"\r\n\r\nAPP\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"ct\"\r\n\r\n\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; name=\"ut\"\r\n\r\n\r\n------WebKitFormBoundary--\r\n"},
      {"高股息",
       "------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"type\"\r\n\r\nRPTA_APP_STOCKSELECT\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"sty\"\r\n\r\nSECUCODE,SECURITY_CODE,SECURITY_NAME_ABBR,NEW_"
       "PRICE,CHANGE_RATE,PE9,TOTAL_MARKET_CAP,ZXGXL\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"filter\"\r\n\r\n(PE9>=0)(PE9<=20)(TOTAL_MARKET_CAP>=20000000000)"
       "(ZXGXL>=4)\r\n------WebKitFormBoundary\r\nContent-Disposition: "
       "form-data; "
       "name=\"p\"\r\n\r\n1\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; "
       "name=\"ps\"\r\n\r\n400\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"sr\"\r\n\r\n-1\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"st\"\r\n\r\nCHANGE_RATE\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"source\"\r\n\r\nSELECT_SECURITIES\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"client\"\r\n\r\nAPP\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"ct\"\r\n\r\n\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; name=\"ut\"\r\n\r\n\r\n------WebKitFormBoundary--\r\n"},
      {"高盈利价值",
       "------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"type\"\r\n\r\nRPTA_APP_STOCKSELECT\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"sty\"\r\n\r\nSECUCODE,SECURITY_CODE,SECURITY_NAME_ABBR,NEW_"
       "PRICE,CHANGE_RATE,PBNEWMRQ,ROE_WEIGHT\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"filter\"\r\n\r\n(PBNEWMRQ>0)(PBNEWMRQ<=5)(ROE_WEIGHT>=10)\r\n---"
       "---WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"p\"\r\n\r\n1\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; "
       "name=\"ps\"\r\n\r\n400\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"sr\"\r\n\r\n-1\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"st\"\r\n\r\nCHANGE_RATE\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"source\"\r\n\r\nSELECT_SECURITIES\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"client\"\r\n\r\nAPP\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"ct\"\r\n\r\n\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; name=\"ut\"\r\n\r\n\r\n------WebKitFormBoundary--\r\n"},
      {"业绩翻倍",
       "------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"type\"\r\n\r\nRPTA_APP_STOCKSELECT\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"sty\"\r\n\r\nSECUCODE,SECURITY_CODE,SECURITY_NAME_ABBR,NEW_"
       "PRICE,CHANGE_RATE,NETPROFIT_YOY_RATIO,TOI_YOY_RATIO\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"filter\"\r\n\r\n(NETPROFIT_YOY_RATIO>100)(TOI_YOY_RATIO>100)"
       "\r\n------WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"p\"\r\n\r\n1\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; "
       "name=\"ps\"\r\n\r\n300\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"sr\"\r\n\r\n-1\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"st\"\r\n\r\nCHANGE_RATE\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"source\"\r\n\r\nSELECT_SECURITIES\r\n------"
       "WebKitFormBoundary\r\nContent-Disposition: form-data; "
       "name=\"client\"\r\n\r\nAPP\r\n------WebKitFormBoundary\r\nContent-"
       "Disposition: form-data; "
       "name=\"ct\"\r\n\r\n\r\n------WebKitFormBoundary\r\nContent-Disposition:"
       " form-data; name=\"ut\"\r\n\r\n\r\n------WebKitFormBoundary--\r\n"},
  };
  stock_map ret;
  std::map<std::string, cpr::AsyncResponse> containers{};
  std::vector<std::string> channels = {
      "北向资金", "估值三低",   "机构主力关注", "高成长优选", "社保大量持股",
      "彼得林奇", "精选白马",   "高送转预期",   "格雷厄姆",   "绩优大盘股",
      "高股息",   "高盈利价值", "业绩翻倍"};

  cpr::Url url = cpr::Url{
      "https://datacenter.eastmoney.com/stock/selection/api/data/get/"};
  std::vector<std::shared_ptr<cpr::Session>> sessions;
  for (auto &channel : channels) {
    std::shared_ptr<cpr::Session> session = std::make_shared<cpr::Session>();
    session->SetUrl(url);
    auto header =
        cpr::Header({{"Content-Type",
                      "multipart/form-data; boundary=----WebKitFormBoundary"}});
    session->SetHeader(header);
    session->SetBody(params[channel]);
    auto spa = session->PostAsync();
    containers[channel] = std::move(spa);
  }
  for (auto &channel : channels) {
    auto r = containers[channel].get();
    auto d = json::parse(r.text);
    if (d["success"]) {
      for (auto &item : d["result"]["data"]) {
        auto &st = ret[item["SECURITY_NAME_ABBR"]];
        std::get<0>(st) = item["SECURITY_NAME_ABBR"];
        std::get<1>(st) = item["SECUCODE"];
        std::get<2>(st).push_back(channel);
      }
    }
  }
  return ret;
}
