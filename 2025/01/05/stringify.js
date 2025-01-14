const { execFile } = require('child_process');
const path = require('path');

const mainPath = './main';
execFile(mainPath, (error, stdout, stderr) => {
  if (error) {
    console.error(`执行错误: ${error.message}`);
  }
  if (stderr) {
    console.error(`标准错误: ${stderr}`);
  }
  const mainOutput = JSON.parse(stdout);
  console.log(mainOutput.uID);
  console.log(mainOutput.message);
  console.log(mainOutput.username);
  console.log(mainOutput.authority_num);
});
