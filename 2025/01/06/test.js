const fetch = require('node-fetch');

(async function() {
   console.log('书籍荐购 start');

   const bookTitle = "this is another book";
   const ISBN = "978123489";
   const recommendTime = new Date().toISOString().split('T')[0];

   try {
      console.log('书籍荐购 表单发送 开始');
      const res = await fetch('http://hk416hasu.fun/api_zhao/bookrecommend', {
         method: 'POST',
         headers: {
            'Content-Type': 'application/json',
         },
         body: JSON.stringify({
            bookTitle: bookTitle,
            ISBN: ISBN,
            recommendTime: recommendTime,
         }),
      });

      console.log('书籍荐购 表单发送 结束');

      if (res.ok) {
         const result = await res.json();
         console.log('书籍荐购 成功', result);
      } else {
         console.log('书籍荐购 失败');
      }
   } catch (error) {
      console.error('书籍荐购出错', error);
   }
})();

