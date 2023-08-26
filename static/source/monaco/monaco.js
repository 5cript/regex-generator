const basename = (path) => {
    return path.substring(path.lastIndexOf('/') + 1);
}

import JSONWorker from 'url:monaco-editor/esm/vs/language/json/json.worker.js';
import CSSWorker from 'url:monaco-editor/esm/vs/language/css/css.worker.js';
import HTMLWorker from 'url:monaco-editor/esm/vs/language/html/html.worker.js';
import TSWorker from 'url:monaco-editor/esm/vs/language/typescript/ts.worker.js';
import EditorWorker from 'url:monaco-editor/esm/vs/editor/editor.worker.js';
import * as monaco from 'monaco-editor/esm/vs/editor/editor.main.js';

const urlFixup = (url) => {
    return `data:text/javascript;charset=utf-8,${encodeURIComponent(`
    importScripts('https://modules/${basename(url)}');`)}`;
}

(() => {
    globalThis.MonacoEnvironment = {
        getWorkerUrl: function (moduleId, label) {
            if (label === 'json') {
                return urlFixup(JSONWorker);
            }
            if (label === 'css' || label === 'scss' || label === 'less') {
                return urlFixup(CSSWorker);
            }
            if (label === 'html' || label === 'handlebars' || label === 'razor') {
                return urlFixup(HTMLWorker);
            }
            if (label === 'typescript' || label === 'javascript') {
                return urlFixup(TSWorker);
            }
            return urlFixup(EditorWorker);
        }
    };

    globalThis.createMonacoEditor = (container) => {
        const editor = monaco.editor.create(container, {
            value: ['function x() {', '\tconsole.log("Hello world!");', '}'].join('\n'),
            language: 'javascript',
            automaticLayout: true
        });
        return editor;
    };
})();
