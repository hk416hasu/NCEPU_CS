/**
 * npm install crypto-js node-fetch@2
 */
const CryptoJS = require("crypto-js");
const querystring = require("querystring");
const fetch = require("node-fetch");

// 云市场分配的密钥Id
const secretId = "AKIDuJ5UiSKdEk9bfS56cbXm8pQc1mnyXp4tuc";
// 云市场分配的密钥Key
const secretKey = "LEt8aBZSXHK7xax6F5mm3jKOn0xCRD5Y55xZSLtQ";
const source = "market";

// 签名
const datetime = new Date().toGMTString();
const signStr = "x-date: " + datetime + "\n" + "x-source: " + source;
const sign = CryptoJS.enc.Base64.stringify(CryptoJS.HmacSHA1(signStr, secretKey));
const auth = `hmac id="${secretId}", algorithm="hmac-sha1", headers="x-date x-source", signature="${sign}"`;

// 请求方法
const method = "GET";

// 请求头
const headers = {
    "X-Source": source,
    "X-Date": datetime,
    "Authorization": auth,
};

// 查询参数
const isbn = process.argv[2];
if (!isbn) {
    console.error("Please provide an ISBN as a command-line argument.");
    process.exit(1);
}

const queryParams = {
    "isbn": isbn,
};

// 请求 URL 参数拼接
let url = "https://service-osj3eufj-1255468759.ap-shanghai.apigateway.myqcloud.com/release/isbn";
if (Object.keys(queryParams).length > 0) {
    url += "?" + querystring.stringify(queryParams);
}

// 发送请求
(async () => {
    try {
        const options = {
            method,
            headers,
        };

        const response = await fetch(url, options);
        const body = await response.text();

        if (!response.ok) {
            console.error("Error:", response.status, response.statusText);
            return;
        }

        console.log(body);
    } catch (error) {
        console.error("Error:", error);
    }
})();

